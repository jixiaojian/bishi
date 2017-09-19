#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n,ans = 0;
    cin >> n;
	double temp=(1+8*n);
    int m=1;
    
	double f = (-1+sqrt(temp))/2;
	//m = (int)f;
	m=ceil(f);
	while(m*(m+1)/2 < n)
    {
        m++;
    }
	cout<<m<<endl;
}