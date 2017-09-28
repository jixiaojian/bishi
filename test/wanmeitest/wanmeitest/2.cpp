#include <iostream>
#include <string>
#include <vector>
#include <map>
#define INT_MAX 2147483647
using namespace std;
int findMin(vector<int> &a,int n,int &MIN)
{
	if(n<0) 
		return 0;
	MIN = a[0];
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(a[i] < MIN)
		{
			MIN = a[i];
			j = i;
		}
	}
	a[j] = INT_MAX;
	return j;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> a;
	int i=0,j=0;
	while(n--)
	{
		cin >> j;
		a.push_back(j);
		i++;
	}
	int MIN;
	map<int,int> m;
	for(int i=0;i<k;i++)
	{
		m[findMin(a,a.size(),MIN)] = MIN;
	}
	for(map<int,int>::iterator i=m.begin();i!= m.end();i++)
		cout<<i->second<<endl;
	return 0;
}