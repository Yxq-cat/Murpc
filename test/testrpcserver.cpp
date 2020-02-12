#include "service.pb.h" // 包含protobuf生成的服务类
#include "rpcserver.h"
#include <string>
using namespace std;


/*
RpcServer：RPC框架的服务类
UserService:它本来是本地服务的一个类，只支持本地方法调用，现在需要
它支持RPC调用----现在的需求！！！

google grpc -》 protobuf 
RPC的实现 - 依赖protobuf本身提供的RPC服务类机制
创建一个服务类的proto配置文件：
1.服务方法的参数打包类型和返回值打包类型 UserServiceRpc
2.服务类和服务的方法
=》 protoc service.proto --cpp_out=./
  生成了 service.pb.cc和service.pb.h
  UserServiceRpc_stub : rpc client用的
  UserServiceRpc ： rpc service用的

UserService 需要继承 UserServiceRpc类，把基类提供的服务方法
进行重写，由框架把参数全部方法request里面，而且把当前的方法调用
已经分发到服务方法上了,基本上做4件事情：
1. 从request获取参数
2. 执行本地服务方法
3. 设置reponse打包返回值
4. 执行回调

*/
// 原来的本地业务方法，现在如果要支持RPC远程服务方法调用   xml json protobuf
class UserService : public UserServiceRpc
{
public:
	// 原先本地的服务方法
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

	// 支持RPC远程调用的服务方法
	virtual void login(::google::protobuf::RpcController* controller,
		const ::LoginRequest* request,
		::LoginResponse* response,
		::google::protobuf::Closure* done)
	{
		// rpc框架把服务调用分发到login方法上 request拿到了rpc client发送过来的数据
		cout << "recv rpc client call login:" << request->name() << " "
			<< request->pwd() << endl;
		// 执行本地的服务
		bool isLoginSuccess = login(request->name(), request->pwd());
		// 设置返回值到protobuf消息上
		response->set_isloginsuccess(isLoginSuccess);
		// 把响应通过网络发送回去
		done->Run(); // 实际在RPC框架层就是一个回调，可以自定义实现任何代码
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
	// 获取RpcServer的实例
	RpcServer *server = RpcServer::getInstance();
	// 注册想发布的Rpc服务
	server->registerService(new UserService());
	// 启动RpcServer epoll_wait
	server->start();  

	return 0;
}