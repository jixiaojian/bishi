#include <iostream>
using namespace std;
//С���ѵ�����������i���ڵ�
void Adjust(int a[],int i,int n)
{
	int j=2*i+1;
	//int min,j;
	while(j < n)
	{
		if(j+1 < n && a[j+1] < a[j])//��ǰ�ڵ����ӽڵ��е���Сֵ����
			j++;
		
		if(a[i] < a[j])   //��ǰ�ڵ�С���ӽڵ��е���Сֵ���������
			break;
		else
		{
			swap(a[i],a[j]);
			i=j;
			j=2*i+1;
		}
	}
}
//����ѵ�����������i���ڵ�
void AdjustBig(int a[],int i,int n)
{
	int j=2*i+1;
	//int min,j;
	while(j < n)
	{
		if(j+1 < n && a[j] < a[j+1])//��ǰ�ڵ����ӽڵ��е����ֵ����
			j++;
		
		if(a[i] > a[j])     //��ǰ�ڵ�����ӽڵ��е����ֵ���������
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
		AdjustBig(a,i,n); //�����ɶ�
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	for(int i=n-1;i>=1;i--)
	{
		swap(a[i],a[0]);        //����������������
		//Adjust(a,0,i);
		AdjustBig(a,0,i);
	}
}