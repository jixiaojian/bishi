#include <iostream>
using namespace std;

int main()
{
	//������float����double���͵ı��������о������ơ�����һ��Ҫ���⽫��������á�==���򡰣�=�������ֱȽϣ�Ӧ���跨ת���ɡ�>=����<=����ʽ��
	float f=0.0000001;
	cout<<f<<endl;
	if(abs(f)<1e-6)   //float��6λ��Чλ,double��15λ��Чλ
		cout<<"f�ܽӽ�0"<<endl;
	else
		cout<<"f���ӽ�0"<<endl;
	return 0;
}