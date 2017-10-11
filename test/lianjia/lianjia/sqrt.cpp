#include <iostream>
using namespace std;
//���ַ�������˼·�Ǹ����ֲ������ƣ�Ҫ����֪������ķ�Χ��ȡ�������ҽ磬Ȼ��ÿ�ο���������������һ�룬
//ֱ�������ҽ��������㷨��ʱ�临�Ӷ���O(logx)���ռ临�Ӷ���O(1)��
int sqrt1(int x) 
{  
    if(x<0) return -1;  
    if(x==0) return 0;  
    int l=1;  
    int r=x/2+1;  
    while(l<=r)  
    {  
        int m = (l+r)/2;  
        if(m<=x/m && x/(m+1)<(m+1))  //m*m���ܻ�Խ�磬���д��m<x/m
            return m;  
        if(x/m<m)  
        {  
            r = m-1;  
        }  
        else  
        {  
            l = m+1;  
        }  
    }  
    return 0;  
} 
//���ַ�
const float eps = 1e-5;
float sqrt2(float x)
{
	if(x<0) 
		return x;
	float l=0.0;
	float tmp=x;
	float r=(l+x)/2.0;	
	while(l<r)
	{
		if(abs(r*r - x)<eps)
			return r;
		else if(r*r > x)
		{
			tmp=r;
			r=(l+r)/2;			
		}
		else if(r*r < x)
		{
			l=r;
			r=tmp;
		}
	}
}
//ţ�ٵ�����
float SqrtByNewton(float x)
{
    float val = x;//����
    float last;//������һ�������ֵ
    do
    {
        last = val;
        val = (val + x/val) / 2;  //val��ֵÿ�θ��¶����ӽ����
    }while(abs(val-last) > eps);
    return val;
}

double myPow(double x, int n) 
    {
        double result=1.0;
        if(n==0 && x!=0.0)
            return 1;
        else if(n<0)
        {
            if(x==0.0)
                return 0;
            n=abs(n);
            for(int i=0;i<n;i++)
            {                
                result=result*x;
            }
            return 1.0/result;    
        }
        else
        {
            for(int i=0;i<n;i++)
            {                
                result=result*x;
            }
            return result;    
        }  
        
    }
int main()
{
	cout<<sqrt1(1.44)<<endl;
	cout<<sqrt2(1.44)<<endl;
	cout<<SqrtByNewton(1.44)<<endl;
	myPow(0.00001,INT_MAX);
	return 0;
}