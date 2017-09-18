#include <iostream>
using namespace std;

double mypow(double d,int n)
{
	double result=1.0;
	if(n==0 && d!=0.0)
		return 1;
	if(n<0)
	{
		if(d == 0.0)
			return 0;
		n = -n;
		while(n--)
		{
			result*=d;
		}
		result = 1.0/result;
	}
	if(n>0)
	{
		while(n--)
		{
			result*=d;
		}
	}
	return result;
}