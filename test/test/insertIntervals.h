#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//in:[1,3][2,6][8,10][15,18] ����[4,9]
//out:[1,3][2,10][15,18]
/*struct Interval 
{
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};*/

class Solution2 
{
public:
	static int compare_interval(Interval a,Interval b)
	{
		return a.start < b.start;
	}
public:
    vector<Interval> insert(vector<Interval>& intervals,Interval newInterval) 
	{
		vector<Interval> result;
		if(intervals.size() == 0)
			result.push_back(newInterval);
		//sort(intervals.begin(),intervals.end(),compare_interval);//��start����
		int i=0;
		while(i<intervals.size() && intervals[i].end < newInterval.start)   //ǰ
		{
			result.push_back(intervals[i++]);
		}
		result.push_back(newInterval);
		while(i<intervals.size() && intervals[i].start < result[result.size()-1].end) //��
		{
			result[result.size()-1].start = min(intervals[i].start,result[result.size()-1].start);
			result[result.size()-1].end = max(intervals[i].end,result[result.size()-1].end);
			i++;
		}
		while(i<intervals.size())   //��
			result.push_back(intervals[i++]);
		return result;
    }
};
