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

// rpc client�����е�rpc���񷽷��������ն���������
void RpcClient::CallMethod(const MethodDescriptor* method,
	RpcController* controller, const Message* request,
	Message* response, Closure* done)
{
		// ��֯rpc client���͵���Ϣ
		auto service = method->service();
		string service_name = service->name();
		string method_name = method->name();

		// ͨ��zkclient����rpc�����Ƿ����
		ZkClient zk;
		zk.start();
		string path = ZkClient::getRootPath() + "/" + service_name + "/" + method_name;
		string host = zk.get(path.c_str());
		if (host.size() == 0) // û�ҵ�rpc�����host
		{
			// ����Ӧ��д�������Ϣ��ֱ�ӷ���
			return;
		}

		// ��װRPC�����ַ���
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

		// Ԥ��һ���ص���������RpcServer�ɹ�������RPC�����ַ���
		sendRpcCallBack_ = [&](const TcpConnectionPtr &con) {
			con->send(request_send_str);
		};

		// Ԥ��һ���ص������첽���յ�rpc server��Ӧ��ʱ�򣬵��ûص�
		responseCallBack_ = [&](string message) {
			response->ParseFromString(message);
		};

		// ����TpcClient������RpcServer������RPC����
		int idx = host.find(':');
		string ip = host.substr(0, idx);
		unsigned short port = atoi(host.substr(idx + 1).c_str());
		client_ = new TcpClient(&loop_, InetAddress(ip, port), "");
		// �������¼���֪ͨ����
		client_->setConnectionCallback(bind(&RpcClient::onConnection, this, _1));
		// ����Ϣ�¼���֪ͨ����
		client_->setMessageCallback(bind(&RpcClient::onMessage, this, _1, _2, _3));
		client_->connect();
		loop_.loop();
}

// ���ӻص� - ��client���ӻ��߶Ͽ����ӣ��ú��������
void RpcClient::onConnection(const TcpConnectionPtr &conn)
{
	if (conn->connected()) // ��ʾ�����Ӵ���
	{
		// ���ӳɹ���������ִ��rpc�����ص�
		sendRpcCallBack_(conn);
	}
	else
	{
		conn->shutdown(); // �ر�����
		loop_.quit(); // �˳��¼�ѭ��
	}
}

// ��Ϣ�ص�
void RpcClient::onMessage(const TcpConnectionPtr& conn, 
	Buffer*buf, Timestamp time)
{
	// �������rpcԶ�̵��÷����ķ���ֵ
	string message = buf->retrieveAllAsString();
	// ���û�����֪ͨRPC���õĽ��
	responseCallBack_(message);
}
