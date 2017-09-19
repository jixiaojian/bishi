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
	int count=0,num=0;
	for(int i=0;i<n;i++)
	{
		count=0;
		int temp=a[i];
		while(temp/10)
		{
			temp=temp/10;
			count++;
		}
		count++;
		for(int j=1;j<n;j++)
		{
			int x=count;
			temp=a[(i+j)%n];
			while(x--)
			{
				temp=temp*10;
			}
			if((temp+a[i])%7==0)
			{
				cout<<temp+a[i]<<" ";
				num++;
			}
		}		
	}
	cout<<endl;
	cout<<num<<endl;
}



