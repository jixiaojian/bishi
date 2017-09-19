#include <iostream>
#include <math.h>
#include <map>
using namespace std;


int main()
{
	int N,x,y;
	cin>>N;
	map<int,int> maxset;
	int inputset[100000000][2];
	int xmax=0,ymax=0,xindex,yindex;
	for(int i=0;i<N;i++)
	{
		cin>>x>>y;
		inputset[i][0]=x;
		inputset[i][1]=y;
		if(x>xmax)
		{	
			xmax=x;
			xindex=i;
		}
		if(y>ymax)
		{	
			ymax=y;
			yindex=i;
		}
	}	

	for(int i=0;i<N;i++)
	{
		if(inputset[i][0] <inputset[xindex][0] ||inputset[i][1] <inputset[yindex][1] )
		{
			
		}
		else
		{
			xindex=i;
			yindex=i;
		}
	}
	cout<<inputset[xindex][0]<<" "<<inputset[xindex][1]<<endl;
	cout<<inputset[yindex][0]<<" "<<inputset[yindex][1]<<endl;
	return 0;
}
