#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//[1,3][2,6][8,10][15,18]
//[1,6][8,10][15,18]
struct Interval 
{
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
public:
	static int compare_interval(Interval a,Interval b)
	{
		return a.start < b.start;
	}
public:
    vector<Interval> merge(vector<Interval>& intervals) 
	{
		vector<Interval> result;
		if(intervals.size()<1)
			return intervals;
		sort(intervals.begin(),intervals.end(),compare_interval);//°´startÅÅÐò
		Interval node = intervals[0];
		for(int i = 1;i < intervals.size();i++)
		{
			Interval tmp = intervals[i];
			if(node.end < tmp.start)
			{
				result.push_back(node);
				node = tmp;
			}
			else
			{
				node.end = max(node.end,tmp.end);
			}
		}
		result.push_back(node);
		return result;
    }
};