#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpparameter);
int main()
{
	int n;
	cin>>n;
	char str[100];
	cin>>str;
	int len = strlen(str);
	char *p = new char[len*sizeof(char)];
	p = str;
	
	while(n--)
	{
		int len = strlen(str);
		while(len-- >= 0)
		{
			HANDLE  hThread1;
			hThread1 = CreateThread(0,0,Fun1Proc,(LPVOID)(p++),0,NULL);
			//CloseHandle(hThread1);
		}
	}	
	return 0;
}
DWORD WINAPI Fun1Proc(LPVOID lpparameter)
{
	char a = *((char*)lpparameter);
	cout<<a;
	return 0;
}
