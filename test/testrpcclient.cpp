#include "service.pb.h"
#include "rpcclient.h"

// 模拟业务代码，RPC方法    用户线程
int main()
{
	UserServiceRpc_Stub stub(new RpcClient());
	// 封装回调，connect成功后，在执行这里的rpc调用
	LoginRequest request;
	request.set_name("zhang san");
	request.set_pwd("888888");
	LoginResponse response;

	stub.login(nullptr, &request, &response, nullptr);

	bool loginstate = response.isloginsuccess();
	cout << "loginstate:" << loginstate << endl;

	return 0;
}
