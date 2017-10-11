#include <iostream>
using namespace std;
//二分法。基本思路是跟二分查找类似，要求是知道结果的范围，取定左界和右界，然后每次砍掉不满足条件的一半，
//直到左界和右界相遇。算法的时间复杂度是O(logx)，空间复杂度是O(1)。
int sqrt1(int x) 
{  
    if(x<0) return -1;  
    if(x==0) return 0;  
    int l=1;  
    int r=x/2+1;  
    while(l<=r)  
    {  
        int m = (l+r)/2;  
        if(m<=x/m && x/(m+1)<(m+1))  //m*m可能会越界，因此写成m<x/m
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
//二分法
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
//牛顿迭代法
float SqrtByNewton(float x)
{
    float val = x;//最终
    float last;//保存上一个计算的值
    do
    {
        last = val;
        val = (val + x/val) / 2;  //val的值每次更新都更接近结果
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