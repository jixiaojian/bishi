#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int l,r;
    cin >> l >> r;
    int m=l;
	int count=0;
	
	if(r < 100)
	{
		for(int i=l/10;i<=r/10;i++)
		{
			if((10*i+i)<=r && (10*i+i)>=l)
				count++;
		}
	}
	while(l <= r && m>=l && m <=r)
	{
		if(r >= 100 && r < 1000)
		{	
			if(l<100)
			{
				for(int i=l/10;i<10;i++)
				{
					if((10*i+i)<=100)
						count++;
				}
				m=100;
			}
			int b=m/100;
			int sh=m%100/10;
			int g=m%10;
			if((b+sh) == g || (b+g) == sh || (g+sh) == b)
			{
				count++;
				m++;				
			}
		}
		else
			break;
	}
	cout<<count<<endl;
    return 0;
}