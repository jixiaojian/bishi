#include <iostream>
using namespace std;
//小根堆调整，调整第i个节点
void Adjust(int a[],int i,int n)
{
	int j=2*i+1;
	//int min,j;
	while(j < n)
	{
		if(j+1 < n && a[j+1] < a[j])//当前节点与子节点中的最小值交换
			j++;
		
		if(a[i] < a[j])   //当前节点小于子节点中的最小值，调整完成
			break;
		else
		{
			swap(a[i],a[j]);
			i=j;
			j=2*i+1;
		}
	}
}
//大根堆调整，调整第i个节点
void AdjustBig(int a[],int i,int n)
{
	int j=2*i+1;
	//int min,j;
	while(j < n)
	{
		if(j+1 < n && a[j] < a[j+1])//当前节点与子节点中的最大值交换
			j++;
		
		if(a[i] > a[j])     //当前节点大于子节点中的最大值，调整完成
			break;
		else
		{
			swap(a[i],a[j]);
			i=j;
			j=2*i+1;
		}
	}
}
void heapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		//Adjust(a,i,n);
		AdjustBig(a,i,n); //调整成堆
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	for(int i=n-1;i>=1;i--)
	{
		swap(a[i],a[0]);        //大根堆排序后递增输出
		//Adjust(a,0,i);
		AdjustBig(a,0,i);
	}
}