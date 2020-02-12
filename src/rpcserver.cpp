#include "rpcserver.h"
#include "rpc_meta.pb.h"
#include "loadxmlconfig.h"
#include <thread>
using namespace std;

RpcServer *RpcServer::rpcServer_ = nullptr;
/*
README.md
build.sh
bin   => ��ִ�г���
lib   => libs.a libc.so
src   => Դ��
include => ͷ�ļ�
build => ������ص��м��ļ�
examples => ʾ������
*/
RpcServer* RpcServer::getInstance()
{
	if (rpcServer_ == nullptr)
	{
		// ���������ļ�����ȡip��port
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
	// �����ӻص�
	server_.setConnectionCallback(bind(&RpcServer::onConnection, this, _1));
	// ����Ϣ�ص�
	server_.setMessageCallback(bind(&RpcServer::onMessage, this, _1, _2, _3));
	// ���÷�����߳����� I/O�߳� �� worker�߳�
	server_.setThreadNum(4);

	// ����zookeeper
	zkclient_.start();
	// ����zk������ά��session
	zkclient_.sendHeartBeat();
}

void RpcServer::start()
{
	server_.start();
	loop_->loop();
}

// ���û����ø÷�������RpcServerע��RPC����
void RpcServer::registerService(google::protobuf::Service *service)
{
	// ��UserService��������з����������Ա������map����
	// ��protobuf�����Service����Ϥһ��
	ServiceInfo sinfo;
	auto service_desc = service->GetDescriptor();
	string service_name = service_desc->name(); // ������
	int method_cnt = service_desc->method_count(); // ��������

	// ��������znode
	string path = zkclient_.getRootPath();
	path += "/" + service_name;
	zkclient_.create(path.c_str(), nullptr, -1);

	for (int i = 0; i < method_cnt; ++i)
	{
		auto method = service_desc->method(i);
		string method_name = method->name();
		sinfo.methodMap_.insert({ method_name , method});

		// �������񷽷�znode
		string methodpath;
		methodpath += (path + "/" + method_name);
		zkclient_.create(methodpath.c_str(), server_.ipPort().c_str(), server_.ipPort().size(), ZOO_EPHEMERAL);
	}
	sinfo.service_ = service;
	serviceMap_.insert({ service_name , sinfo });
}

// ��������
void RpcServer::onConnection(const TcpConnectionPtr &con)
{
	// rpc client�յ���Ӧ���յ��������ӹر�����
	if (!con->connected())
	{
		con->shutdown(); // close(fd);
	}
}

// ������ղ�������Ӧ��Ϣ�� 
void RpcServer::onMessage(const TcpConnectionPtr& con,
	Buffer *buf,
	Timestamp time)
{
	// ͷ�ĳ��ȣ����ֽڴ洢��+ͷ��Ϣ�����������|��������+protobuf���л�������
	// 4 UserService|login protobuf(args)
	string message = buf->retrieveAllAsString();
	
	// insert ���ֽڲ�������ݣ�ͨ��copy���ֽڿ����������ж�ȡ
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

	// ����service_name+method_name �ַ���������
	ServiceInfo info = serviceMap_[service_name];
	auto service = info.service_;
	auto method = info.methodMap_[method_name];
	// Message*����ָ������
	auto request = service->GetRequestPrototype(method).New();
	auto response = service->GetResponsePrototype(method).New();
	request->ParseFromString(args_string);

	// response
	auto done = google::protobuf::NewCallback<RpcServer, 
		const TcpConnectionPtr&,
		google::protobuf::Message*>(this,
		&RpcServer::sendRpcResponse // Arg1  Arg2
		, con, response);// const TcpConnectionPtr

	// ���񷽷��ķַ�����
	service->CallMethod(method, nullptr, request, response,
		done);
}

void RpcServer::sendRpcResponse(const TcpConnectionPtr &con,
	 google::protobuf::Message *response)
{
	// �����룺2
	// errcode + ��reponse��Ϣ���л���protobuf��Ϣ��con->send������Ӧ
	string response_send_str;
	response->SerializeToString(&response_send_str);
	con->send(response_send_str);
	con->shutdown(); // RpcServer�������Ͽ�����
}
