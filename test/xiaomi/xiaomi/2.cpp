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
/*��������Ҫһ������Ĺ���������ʱ��ѡ��std::map
����Ч�ʷ��棺unordered_map��ߣ���mapЧ�ʽϵ͵� �ṩ���ȶ�Ч�ʺ���������С�
ռ���ڴ淽�棺map�ڴ�ռ���Եͣ�unordered_map�ڴ�ռ���Ը�,���������Գɱ����ġ�
��Ҫ�������������ٲ���ɾ�����������Ըߵ��ڴ�ʱ��unordered_map�����������ȶ�����ɾ��Ч�ʣ��ڴ������ʱ����map��
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
            a.insert(MAP::value_type(nums[i],i)); //map����ֵ�Զ�����,�������ظ��ļ�ֵ.//unordered_map���ᰴ��ֵ�Զ�����,���������ظ��ļ�ֵ
        }//multimap����ֵ�Զ�����,�������ظ��ļ�ֵ
		for(int i=0;i<nums.size();i++)
        {
			MAP::iterator it=a.find(target-nums[i]);//����ֵ����6-6=3
			//MAP::iterator itself=a.find(nums[i]);
			if(it!=a.end() && it->second!=i) //�ҵ�
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
		if(it!=a.end())  //�ҵ�
			cout<<it->second<<endl;
	}
	string str2="/a";
	MAP::iterator it=a.find(str2);
	if(it==a.end())
	{
		//û�ҵ�
		a.insert(MAP::value_type(str2,++k));
	}
	else
	{
		//�ҵ�
		cout<<it->first<<" "<<it->second<<endl;
	} 	
	cout<<a.count(str)<<endl;  //����ָ��Ԫ�س��ֵĴ���
	cout<<a.erase(str2)<<endl;  //ͨ���ؼ���ɾ��Ԫ��,ɾ������1,���򷵻�0
	cout<<a.size()<<endl;       //mapԪ�ظ���

}