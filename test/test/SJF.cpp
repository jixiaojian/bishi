#include <iostream>
#include <vector>
using namespace std;

int findmin_duration(vector<int> &a,int *b,int end_time, int n)  
{  
    int min = INT_MAX;  
    int pos = 0;  
    for (int i = 1; i < n; i++)  
    {  
        if (a[i] < min && b[i] <= end_time)  //所有要执行的任务的请求时间必须在上一个任务完成的时间内。
        {  
            min = a[i];  
            pos = i;  
        }  
    }  
    a[pos] = INT_MAX;  
    return pos;  
}    
float average_wait_time(int *requestTimes, int *durations, int n)  
{  
    vector<int> durate(n,0);  
    vector<int> startTime(n, 0);  
    vector<int> endTime(n, 0);  
    vector<int> waitTime(n, 0);  
    int i;  
    for (i = 0; i < n; i++)  
        durate[i] = durations[i];  
    startTime[0] = requestTimes[0];  
    endTime[0] = durations[0] + startTime[0];    //完成时间=开始执行时间+服务持续时间
    waitTime[0] = startTime[0] - requestTimes[0];  //等待时间=开始执行时间-请求时间（到达时间）
    int minIndex = 0;  
    int lastIndex = minIndex;  
    for (i = 1; i < n; i++)  
    {  
        minIndex = findmin_duration(durate, requestTimes, endTime[lastIndex], n);  
        startTime[minIndex] =  endTime[lastIndex];    //下个进程/任务的开始时间为上一进程的结束时间
        endTime[minIndex] = durations[minIndex] + startTime[minIndex];  
        waitTime[minIndex] = startTime[minIndex] - requestTimes[minIndex];  
        lastIndex = minIndex;  
    }  
  
    int s = 0;  
    for (i = 0; i < n; i++)  
        s += waitTime[i];  
    float avageTime = (float)s / (float)n;  
    return avageTime;  
}  
int SJF()  
{  
    //int requestTimes[4] = { 0, 1, 3, 9 };  
    //int durations[4] = { 2, 1, 7, 5 };  
    int requestTimes[] = { 0, 2, 4, 5 };  
    int durations[] = { 7, 4, 1, 4 };  
    cout << average_wait_time(requestTimes, durations, 4) << endl;  
    getchar();  
    return 0;  
}  
