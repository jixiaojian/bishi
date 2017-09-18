#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n,m;
	double result=0;
	while(cin>>n>>m)
	{
		double n1=n;
		for(int i=0;i<m;i++)
		{
			result+=n1;
			n1= sqrt(n1);
		}
		cout<<result<<endl;
	}
	return 0;
}