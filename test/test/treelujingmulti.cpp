//vector::reserve��vector::resize������reserveֻ�Ǳ���һ����С�Ŀռ��С����resize���ǶԻ������������·��䣬
//����������Ŀ����ȷ����ʱ����Ԥ��ռ��С�Ǻ��б�Ҫ�ġ�ֱ��push_back����Ƶ���ƶ����Ǻ�ʱ����Ȼ�ˣ�����С�Ŀ��Ժ��Եģ���
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