#include <iostream>
using namespace std;
#define N 7
void fun1()
{
	int a[N]={1,2,3,4,5,6,7};
	int i,t;
	int *p=&a[0],*q=&a[N-1];
	while(p<q)
	{
		t=*p;
		*p=*q;
		*q=t;
		p++;
		q--;
	}
	for(int i=0;i<N;i++)
		cout<<a[i];
}
int f(int m,int n)
{
	if(m==0)
		return n+1;
	else if(n==0)
		return f(m-1,1);
	else
		return f(m-1,f(m,n-1));
}
int main()
{
	fun1();
	cout<<endl;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++)
			cout<<"("<<i<<","<<j<<")"<<f(i,j)<<endl;
	cout<<f(3,3)<<endl;
	return 0;
}