#include "service.pb.h"
#include "rpcclient.h"

// ģ��ҵ����룬RPC����    �û��߳�
int main()
{
	UserServiceRpc_Stub stub(new RpcClient());
	// ��װ�ص���connect�ɹ�����ִ�������rpc����
	LoginRequest request;
	request.set_name("zhang san");
	request.set_pwd("888888");
	LoginResponse response;

	stub.login(nullptr, &request, &response, nullptr);

	bool loginstate = response.isloginsuccess();
	cout << "loginstate:" << loginstate << endl;

	return 0;
}
