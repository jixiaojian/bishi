#include <iostream>
#include <string> 
#include <map>
#include <unordered_map>
#include <hash_map>
#include <iterator>
#include <vector>
using namespace std;

//����a[N]�������1 ��N-1 ����������ĳ�����ظ�һ��
int finddup(int a[],int n)
{
	map<int,int> temp;
	for(int i=0;i< n+1;i++)
	{
		if(temp.count(a[i]))
			return a[i];
		else
			temp[a[i]]=i;
	}
}


int main()
{
	int n=100;
	int a[101];
	for(int i=0;i< n+1;i++)
	{		
		a[i]=rand()%(n);
		cout<<a[i]<<" ";
	}
	cout<<endl;
	//a[100]=rand()%(n);
	cout<<finddup(a,n)<<endl;
}