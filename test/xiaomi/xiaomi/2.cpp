#include <iostream>
#include <string> 
#include <map>
#include <unordered_map>
#include <hash_map>
#include <iterator>
#include <vector>
using namespace std;
//Given nums = [2, 7, 11, 15], target = 9,
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
/*当我们需要一个有序的关联容器的时候，选择std::map
运行效率方面：unordered_map最高，而map效率较低但 提供了稳定效率和有序的序列。
占用内存方面：map内存占用略低，unordered_map内存占用略高,而且是线性成比例的。
需要无序容器，快速查找删除，不担心略高的内存时用unordered_map；有序容器稳定查找删除效率，内存很在意时候用map。
*/
vector<int> twoSum(vector<int> &numbers, int target) 
{
	int n = numbers.size();
	vector<int> result;
	map<int, int> index;
	for (int i = 0; i < n; i++) 
	{
		if (index.count(numbers[i]) != 0) 
		{
			// if exists
			result.push_back(index[numbers[i]]);
			result.push_back(i);
			break;
		} 
		index[target - numbers[i]] = i; 
	}
	return result;
}
 
vector<int> mytwoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        //typedef unordered_map<int,int> MAP;
		typedef multimap<int,int> MAP;
		MAP a;
        for(int i=0;i<nums.size();i++)
        {
            a.insert(MAP::value_type(nums[i],i)); //map按键值自动排序,不能有重复的键值.//unordered_map不会按键值自动排序,不可以有重复的键值
        }//multimap按键值自动排序,可以有重复的键值
		for(int i=0;i<nums.size();i++)
        {
			MAP::iterator it=a.find(target-nums[i]);//按键值查找6-6=3
			//MAP::iterator itself=a.find(nums[i]);
			if(it!=a.end() && it->second!=i) //找到
			{				
				result.push_back(it->second);
				result.push_back(i);
				break;
			}
		}        
        return result;
    }
int main()
{
	vector<int> num,result;
	num.push_back(3);
	num.push_back(3);
	//num.push_back(3);
	//num.push_back(15);
	result=twoSum(num,6);
	cout<<result[0]<<" "<<result[1]<<endl;
	
	string str;
	int k;
	typedef map<string,int> MAP;
	MAP a;
	while(cin>>str>>k)
	{
		if(str=="-")
			break;
		a.insert(MAP::value_type(str,k));
	}
	while(cin>>str)
	{
		MAP::iterator it=a.find(str);
		if(it!=a.end())  //找到
			cout<<it->second<<endl;
	}
	string str2="/a";
	MAP::iterator it=a.find(str2);
	if(it==a.end())
	{
		//没找到
		a.insert(MAP::value_type(str2,++k));
	}
	else
	{
		//找到
		cout<<it->first<<" "<<it->second<<endl;
	} 	
	cout<<a.count(str)<<endl;  //返回指定元素出现的次数
	cout<<a.erase(str2)<<endl;  //通过关键字删除元素,删除返回1,否则返回0
	cout<<a.size()<<endl;       //map元素个数

}