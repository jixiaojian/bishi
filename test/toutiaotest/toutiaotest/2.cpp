#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int n,m;
	double result=0;
	while(cin>>m>>n)
	{
		int flag=0;
		for(int i=m;i<=n;i++)
		{
			int b=i/100;
			int sh=i/10%10;
			int g= i%100%10;
			if(i == b*b*b +sh*sh*sh +g *g*g)
				{
					cout<<i<<" ";
					flag=1;
			    }	
		}
		if(flag==0)
			cout<<"no";
		cout<<endl;		
	}
	return 0;
}