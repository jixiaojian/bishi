//vector::reserve和vector::resize的区别。reserve只是保持一个最小的空间大小，而resize则是对缓冲区进行重新分配，
//对于数据数目可以确定的时候，先预设空间大小是很有必要的。直接push_back数据频繁移动很是耗时（当然了，数据小的可以忽略的）。
#include <iostream>
#include <vector>
using namespace std;

int callujingmulti(int num,vector<int> values,vector<vector<int>> edges)
{
	int i=0,j=1,k=0;
	vector<vector<int>> lu;
	//lu.reserve(100);
	while(i < edges.size() && j < edges.size())
	{
		
		if(edges[i][1] == edges[j][0])
		{
			vector<int> temp;
			temp.push_back(edges[i][0]);
			temp.push_back(edges[i][1]);
			temp.push_back(edges[j][1]);
			lu.push_back(temp);		
			i=j;
			j++;
		}
		else
		{
			vector<int> temp;
			temp.push_back(edges[i][0]);
			temp.push_back(edges[i][1]);
			lu.push_back(temp);		
			i++;
			j+=2;
		}	
	}
	int MAX = INT_MIN;
	for(int i=0;i<lu.size();i++)
	{
		int value =1;
		for(int j=0;j<lu[i].size();j++)
		{
			value *= values[lu[i][j]];
		}
		if(value > MAX)
			MAX = value;
	}
	return MAX;
}