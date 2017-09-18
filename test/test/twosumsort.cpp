#include <iostream>
#include <vector>
#include <array>
using namespace std;
vector<int> twosum(vector<int> arr,int start,int end,int first,int k,vector<int> &result);

vector<int> twosumsort(vector<int> arr,int k)
{
	 vector<int> result;
     if(arr.size()<=0)
	  {
		  return arr;
      }
     int length = arr.size();
	 sort(arr.begin(),arr.end());
     int start = 0;
     int end = length - 1;

     while(start < end)
	  {
         while(arr[start] == arr[start+1])
		  {
             start++;
          }
         while(arr[end] == arr[end-1])
		  {
             end--;
          }
         if(arr[start] + arr[end] == k)
		  {
			  result.push_back(arr[start]);
			  result.push_back(arr[end]);//保存数，不是索引号，因为已排序了
             start ++;
          }
         if(arr[start]+arr[end] < k)
		  {
             start++;
          }
         if(arr[start]+arr[end] > k)
		  {
             end--;
          }
     }
	 return result;
}

vector<int> threesumsort(vector<int> arr,int k)
{
	 vector<int> result;
     if(arr.size()<=0)
	  {
          return arr;
      }
	int len = arr.size();
	sort(arr.begin(),arr.end());
	for(int i = 0;i < len;i++)
	{
		if(i<len-1 && arr[i] == arr[i+1])
			continue;
		result = twosum(arr,i,len -1,arr[i],k - arr[i],result);
	}
	return result;
}
vector<int> twosum(vector<int> arr,int start,int end,int first,int k,vector<int> &result)
{
	 //vector<int> result;    
     //int length = arr.size();
	 //sort(arr.begin(),arr.end());
     //int start = 0;
     //int end = length - 1;

     while(start < end)
	  {
         while(arr[start] == arr[start+1])
		  {
             start++;
          }
         while(arr[end] == arr[end-1])
		  {
             end--;
          }
         if(arr[start] + arr[end] == k)
		  {
			  result.push_back(first);       //三个数
			  result.push_back(arr[start]);
			  result.push_back(arr[end]);
              start ++;
          }
         if(arr[start]+arr[end] < k)
		  {
             start++;
          }
         if(arr[start]+arr[end] > k)
		  {
             end--;
          }
     }
	 return result;
}