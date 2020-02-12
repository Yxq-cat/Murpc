#include "rpcclient.h"
#include "rpc_meta.pb.h"
#include <thread>

RpcClient::RpcClient()
	:client_(nullptr)
{}

RpcClient::~RpcClient()
{
	delete client_;
	client_ = nullptr;
}

// rpc client端所有的rpc服务方法调用最终都到达这里
void RpcClient::CallMethod(const MethodDescriptor* method,
	RpcController* controller, const Message* request,
	Message* response, Closure* done)
{
		// 组织rpc client发送的消息
		auto service = method->service();
		string service_name = service->name();
		string method_name = method->name();

		// 通过zkclient查找rpc服务是否存在
		ZkClient zk;
		zk.start();
		string path = ZkClient::getRootPath() + "/" + service_name + "/" + method_name;
		string host = zk.get(path.c_str());
		if (host.size() == 0) // 没找到rpc服务的host
		{
			// 这里应该写入错误信息，直接返回
			return;
		}

		// 组装RPC请求字符串
		rpc_header header;
		header.set_service_name(service_name);
		header.set_method_name(method_name);
		string rpc_header_str;
		header.SerializeToString(&rpc_header_str);
		int header_size = rpc_header_str.size();

		string rpc_args_str;
		request->SerializeToString(&rpc_args_str);

		string request_send_str;
		request_send_str.insert(0, string((char*)&header_size, 4));
		request_send_str += rpc_header_str;
		request_send_str += rpc_args_str;

		cout << "============================================" << endl;
		cout << "header_size:" << header_size << endl;
		cout << "rpc_header_str:" << rpc_header_str << endl;
		cout << "service_name:" << service_name << endl;
		cout << "method_name:" << method_name << endl;
		cout << "rpc_args_str:" << rpc_args_str << endl;
		cout << "============================================" << endl;

		// 预设一个回调，当连接RpcServer成功，发送RPC请求字符串
		sendRpcCallBack_ = [&](const TcpConnectionPtr &con) {
			con->send(request_send_str);
		};

		// 预设一个回调，当异步接收到rpc server响应的时候，调用回调
		responseCallBack_ = [&](string message) {
			response->ParseFromString(message);
		};

		// 创建TpcClient，连接RpcServer，发送RPC请求
		int idx = host.find(':');
		string ip = host.substr(0, idx);
		unsigned short port = atoi(host.substr(idx + 1).c_str());
		client_ = new TcpClient(&loop_, InetAddress(ip, port), "");
		// 绑定连接事件的通知函数
		client_->setConnectionCallback(bind(&RpcClient::onConnection, this, _1));
		// 绑定消息事件的通知函数
		client_->setMessageCallback(bind(&RpcClient::onMessage, this, _1, _2, _3));
		client_->connect();
		loop_.loop();
}

// 连接回调 - 有client连接或者断开连接，该函数会调用
void RpcClient::onConnection(const TcpConnectionPtr &conn)
{
	if (conn->connected()) // 表示新连接创建
	{
		// 连接成功，在这里执行rpc方法回调
		sendRpcCallBack_(conn);
	}
	else
	{
		conn->shutdown(); // 关闭连接
		loop_.quit(); // 退出事件循环
	}
}

// 消息回调
void RpcClient::onMessage(const TcpConnectionPtr& conn, 
	Buffer*buf, Timestamp time)
{
	// 这里接收rpc远程调用方法的返回值
	string message = buf->retrieveAllAsString();
	// 给用户调用通知RPC调用的结果
	responseCallBack_(message);
}
