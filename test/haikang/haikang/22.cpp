#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	//ֻ�ж����һλ
	if(a[n-1]==1)
		cout<<"Alice"<<endl;
	else
		cout<<"Bob"<<endl;
	return 0;
}