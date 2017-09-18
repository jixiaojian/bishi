#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//-5 10 -6 -10 20
void getMaxSeq(int val[], int count)  
{  
    int sum = 0, b = 0;  
    int start = -1, end;  
      
    for(int i=0; i<count; i++)  
    {  
        if(b > 0)  
            b += val[i];  
        else  
            b = val[i];  
          
        if(b > sum)  
        {  
            if(start == -1)  
                start = i;  
            end = i;  
            sum = b;  
        }  
    }  
      
    for(int i=start; i<=end; i++)  
        cout << val[i] << " ";  
    cout << endl;  
} 
int maxSubArray(vector<int>& nums) 
{
    int sum=nums[0];
    int res=nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        sum=max(sum+nums[i],nums[i]);
        res=max(res,sum);
    }
    return res;
}
int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int> pq;//默认优先级进队方式为less。队首大
    for(int i=0; i<nums.size(); i++)
    {
        pq.push(nums[i]);
    }
    for(int i=0; i<k-1; i++)
        pq.pop();
    return pq.top();
}
