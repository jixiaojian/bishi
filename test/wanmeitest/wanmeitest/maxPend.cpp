#include <iostream>
#include <set>
#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int maxStipend(int numOfDays, int taskList[][2])
{
    // WRITE YOUR CODE HERE 
    int count=0;
   
    if(taskList[1][1]-taskList[1][0] < 4)
        {
            count += taskList[0][1];
        }
    for(int i=2;i<numOfDays;i++)
    {
        if(taskList[i][1]-taskList[i][0] < 4)
        {
            count += taskList[i-1][0];
			if(i==numOfDays-1)
				count += taskList[i][0];
        }
        else
        {
                count += taskList[i][1];
				i++;
        }
    }
    return count;
}
int main()
{
	int n=5;
	int task[][2]={1,6,1,2,1,9,1,10,1,13};
	cout<<maxStipend(n, task)<<endl;
}