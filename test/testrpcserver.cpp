#include "service.pb.h" // ����protobuf���ɵķ�����
#include "rpcserver.h"
#include <string>
using namespace std;


/*
RpcServer��RPC��ܵķ�����
UserService:�������Ǳ��ط����һ���ֻ֧࣬�ֱ��ط������ã�������Ҫ
��֧��RPC����----���ڵ����󣡣���

google grpc -�� protobuf 
RPC��ʵ�� - ����protobuf�����ṩ��RPC���������
����һ���������proto�����ļ���
1.���񷽷��Ĳ���������ͺͷ���ֵ������� UserServiceRpc
2.������ͷ���ķ���
=�� protoc service.proto --cpp_out=./
  ������ service.pb.cc��service.pb.h
  UserServiceRpc_stub : rpc client�õ�
  UserServiceRpc �� rpc service�õ�

UserService ��Ҫ�̳� UserServiceRpc�࣬�ѻ����ṩ�ķ��񷽷�
������д���ɿ�ܰѲ���ȫ������request���棬���Ұѵ�ǰ�ķ�������
�Ѿ��ַ������񷽷�����,��������4�����飺
1. ��request��ȡ����
2. ִ�б��ط��񷽷�
3. ����reponse�������ֵ
4. ִ�лص�

*/
// ԭ���ı���ҵ�񷽷����������Ҫ֧��RPCԶ�̷��񷽷�����   xml json protobuf
class UserService : public UserServiceRpc
{
public:
	// ԭ�ȱ��صķ��񷽷�
	bool login(string name, string pwd)
	{
		cout << "call UserService::login->";
		cout << "name:" << name << " ";
		cout << "pwd:" << pwd << endl;
		return true;
	}
	bool reg(int id, string name, int age, int sex)
	{
		cout << "call UserService::reg->";
		cout << "id:" << id << " ";
		cout << "name:" << name << " ";
		cout << "age:" << age << endl;
		cout << "sex:" << sex << endl;
	}

	// ֧��RPCԶ�̵��õķ��񷽷�
	virtual void login(::google::protobuf::RpcController* controller,
		const ::LoginRequest* request,
		::LoginResponse* response,
		::google::protobuf::Closure* done)
	{
		// rpc��ܰѷ�����÷ַ���login������ request�õ���rpc client���͹���������
		cout << "recv rpc client call login:" << request->name() << " "
			<< request->pwd() << endl;
		// ִ�б��صķ���
		bool isLoginSuccess = login(request->name(), request->pwd());
		// ���÷���ֵ��protobuf��Ϣ��
		response->set_isloginsuccess(isLoginSuccess);
		// ����Ӧͨ�����緢�ͻ�ȥ
		done->Run(); // ʵ����RPC��ܲ����һ���ص��������Զ���ʵ���κδ���
	}
	virtual void reg(::google::protobuf::RpcController* controller,
		const ::RegRequest* request,
		::RegResponse* response,
		::google::protobuf::Closure* done)
	{

	}
};

int main()
{
	// ��ȡRpcServer��ʵ��
	RpcServer *server = RpcServer::getInstance();
	// ע���뷢����Rpc����
	server->registerService(new UserService());
	// ����RpcServer epoll_wait
	server->start();  

	return 0;
}