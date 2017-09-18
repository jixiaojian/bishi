#include <iostream>
#include <vector>
using namespace std;

vector<int> twosum(vector<int> num,int target)
{
	vector<int> result;
	for(int i = 0;i<num.size()-1;i++)
		for(int j=i+1;j<num.size();j++)
		{
			if(num[i]+num[j] == target)
			{
				result.push_back(i);
				result.push_back(j);
			}
		}
	return result;
}