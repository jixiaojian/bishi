#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int findMin(int **vec2,int i,int j)
{
	int MIN=vec2[i][j];
	for(int k=0;k<4;k++)
	{
		if(vec2[k][j]<MIN)
			MIN=vec2[k][j];
	}
	return MIN;
	
}
int main()
{
	int (*p)[3];//pΪһ��ָ�룬ָ��3��Ԫ�ص�����
	int *q[3];  //qΪ����3��ָ�������
	int a[3][3]; //a��һ��ָ��
	p=a;
	//q=a;����
	int T,n,k;
	cin>>T;
	map<int,vector<int>> M;
	int  *vec2[100];
	vector<int> vec;
	int result=0;
	while(T--)
	{
		cin>>n;
		for(int j=0;j<4;j++)
			for(int i=0;i<n;i++)
			{
				cin>>k;
				vec2[j][i]=k;
			}
	}
	for(int j=0;j<4;j++)
		for(int i=0;i<n;i++)
		{
			result+=findMin(vec2,j,i);
		}
	
	cout<<result<<endl;
	cout<<"ENWS"<<endl;
}