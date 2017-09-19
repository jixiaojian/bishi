#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	cin>>num;
	int a[100];
	vector<int> value;
	int sum=0;
	for(int i=0;i<num;i++)
		cin>>a[i];
	for(int i=0;i<num;i++)
	{
		value.push_back(a[i]*a[i]);		
		sum+=a[i];
	}
	for(int i=0;i<num-1;i++)
	{
		value.push_back(a[i+1]*(a[i]+a[i+1]));
	}
	value.push_back(a[num-1]*sum);
	sort(value.begin(),value.end());
	cout<<value[value.size()-1]<<endl;
	return 0;
}