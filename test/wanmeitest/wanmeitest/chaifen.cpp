#include <iostream>
#include <set>
#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//自然数拆分
int count(int n)
{
	int sum=0;
	set<vector<int>> vec;
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	int i=1;
	while(i<n)
	{
		for(int k=1;k<=n/i;k++)
		{
			vector<int> v;
			int m=k;
			while(m--)
				v.push_back(i);
			v.push_back(n-k*i);
			sort(v.begin(),v.end());
			if(v[0]!=0)
			{
				vec.insert(v);				
			}
		}
		i++;
	}
	sum=vec.size()+1;
	return sum;
	
}
int main()
{
	int n;
	while(cin>>n)
		cout<<count(n)<<endl;
	return 0;
}
