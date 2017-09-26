#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin>>n;
	int a[100];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	map<int,int> b;	
	int k=0;
	//cin>>k;
	for(int j=0;j<m;j++)
	{		
		cin>> k ;
		cin>> b[k];			
	}
	int result=0;
	for(int i=1;i<=n;i++)
	{
		result+=a[i]*b[i];
	}
	cout<<result<<endl;
	return 0;
}