#include "rpcserver.h"
#include "rpc_meta.pb.h"
#include "loadxmlconfig.h"
#include <thread>
using namespace std;

RpcServer *RpcServer::rpcServer_ = nullptr;
/*
README.md
build.sh
bin   => 可执行程序
lib   => libs.a libc.so
src   => 源码
include => 头文件
build => 编译相关的中间文件
examples => 示例代码
*/
RpcServer* RpcServer::getInstance()
{
	if (rpcServer_ == nullptr)
	{
		// 加载配置文件，读取ip和port
		static EventLoop loop;
		// ip:port
		static InetAddress addr(XmlConfig::getInstance().getRpcServerIp(),
			XmlConfig::getInstance().getRpcServerPort());
		// RPC Server   bind  listen 
		rpcServer_ = new RpcServer(&loop, addr, "RpcServer");
	}
	return rpcServer_;
}

RpcServer::RpcServer(EventLoop *loop, 
	const InetAddress &addr, 
	const string& name)
	:server_(loop, addr, name)
	, loop_(loop)
{
	// 绑定连接回调
	server_.setConnectionCallback(bind(&RpcServer::onConnection, this, _1));
	// 绑定消息回调
	server_.setMessageCallback(bind(&RpcServer::onMessage, this, _1, _2, _3));
	// 设置服务端线程数量 I/O线程 和 worker线程
	server_.setThreadNum(4);

	// 连接zookeeper
	zkclient_.start();
	// 发送zk心跳，维护session
	zkclient_.sendHeartBeat();
}

void RpcServer::start()
{
	server_.start();
	loop_->loop();
}

// 让用户调用该方法，向RpcServer注册RPC服务
void RpcServer::registerService(google::protobuf::Service *service)
{
	// 把UserService里面的所有方法都填入成员变量的map表当中
	// 把protobuf里面的Service类熟悉一下
	ServiceInfo sinfo;
	auto service_desc = service->GetDescriptor();
	string service_name = service_desc->name(); // 服务名
	int method_cnt = service_desc->method_count(); // 方法数量

	// 创建服务znode
	string path = zkclient_.getRootPath();
	path += "/" + service_name;
	zkclient_.create(path.c_str(), nullptr, -1);

	for (int i = 0; i < method_cnt; ++i)
	{
		auto method = service_desc->method(i);
		string method_name = method->name();
		sinfo.methodMap_.insert({ method_name , method});

		// 创建服务方法znode
		string methodpath;
		methodpath += (path + "/" + method_name);
		zkclient_.create(methodpath.c_str(), server_.ipPort().c_str(), server_.ipPort().size(), ZOO_EPHEMERAL);
	}
	sinfo.service_ = service;
	serviceMap_.insert({ service_name , sinfo });
}

// 负责连接
void RpcServer::onConnection(const TcpConnectionPtr &con)
{
	// rpc client收到响应，收到它的连接关闭请求
	if (!con->connected())
	{
		con->shutdown(); // close(fd);
	}
}

// 负责接收并发送响应消息的 
void RpcServer::onMessage(const TcpConnectionPtr& con,
	Buffer *buf,
	Timestamp time)
{
	// 头的长度（按字节存储）+头信息（服务对象名|方法名）+protobuf序列化的数据
	// 4 UserService|login protobuf(args)
	string message = buf->retrieveAllAsString();
	
	// insert 按字节插入的数据，通过copy按字节拷贝出来进行读取
	int header_size = 0;
	message.copy((char*)&header_size, sizeof(int), 0);

	string header_string = message.substr(4, header_size);
	rpc_header header;
	header.ParseFromString(header_string);
	string service_name = header.service_name();
	string method_name = header.method_name();

	string args_string = message.substr(4 + header_size);

	cout << "============================================" << endl;
	cout << "header_size:" << header_size << endl;
	cout << "header_string:" << header_string << endl;
	cout << "service_name:" << service_name << endl;
	cout << "method_name:" << method_name << endl;
	cout << "args_string:" << args_string << endl;
	cout << "============================================" << endl;

	// 根据service_name+method_name 分发方法调用
	ServiceInfo info = serviceMap_[service_name];
	auto service = info.service_;
	auto method = info.methodMap_[method_name];
	// Message*基类指针类型
	auto request = service->GetRequestPrototype(method).New();
	auto response = service->GetResponsePrototype(method).New();
	request->ParseFromString(args_string);

	// response
	auto done = google::protobuf::NewCallback<RpcServer, 
		const TcpConnectionPtr&,
		google::protobuf::Message*>(this,
		&RpcServer::sendRpcResponse // Arg1  Arg2
		, con, response);// const TcpConnectionPtr

	// 服务方法的分发调用
	service->CallMethod(method, nullptr, request, response,
		done);
}

void RpcServer::sendRpcResponse(const TcpConnectionPtr &con,
	 google::protobuf::Message *response)
{
	// 错误码：2
	// errcode + 把reponse消息序列化成protobuf消息，con->send发送响应
	string response_send_str;
	response->SerializeToString(&response_send_str);
	con->send(response_send_str);
	con->shutdown(); // RpcServer端主动断开连接
}
