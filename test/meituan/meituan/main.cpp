#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int x;
	vector<int> a;
	for(int i=0;i<N;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	int k;
	cin>>k;
	int sum=0;
	//vector<int> result;
    int MAX=INT_MIN;
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			sum+=a[j];
			if(sum % k ==0)
            {
				//result.push_back(j+1-i);
                if(j+1-i>MAX)
                    MAX=j+1-i;
            }
		}
	}
	if(MAX==INT_MIN)
		cout<<0<<endl;
	else
	{
		cout<<MAX<<endl;
	}
	return 0;
}

