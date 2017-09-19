#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Idea
{
	 int num;
	 int pm;
	 int st;
	 int p;
	 int ct;
};
int main()
{
	int N,M,P;
	cin>>N>>M>>P;
	int idea[3000][4];
	int mintime=3000;
	int outtime[3000];
	for(int i=0;i<P;i++)
		cin>>idea[i][0]>>idea[i][1]>>idea[i][2]>>idea[i][3];
	for(int i=0;i<P;i++)
	{
		if(idea[i][2]<=mintime)
			mintime=idea[i][2];
	}
	return 0;
}

#include<iostream>

using namespace std;
typedef struct{
    int num;
    int pm;
    int time;
    int level;
    int cost;
    int end_time;
    int worker;
}Idea;

bool compare(Idea a, Idea b){
    if(a.level > b.level){
        return true;
    }
    if(a.level < b.level){
        return false;
    }
    if(a.cost < b.cost){
        return true;
    }
    if(a.cost > b.cost){
        return false;
    }
    if(a.pm < b.pm){
        return true;
    }
    if(a.pm > b.pm){
        return false;
    }
    if(a.time < b.time){
        return true;
    }
    if(a.time > b.time){
        return false;
    }
}
int find_work(Idea* ideas, int idea_num, int time){
    int m =-1;
    int pm = -1;
    Idea idea;
    idea.time = 4000;
    for(int i=0;i<idea_num;++i )
	{
        if(ideas[i].time<=time && ideas[i].worker ==0)
		{
            if(ideas[i].pm == pm)
			{
                if(compare(ideas[i],idea))
				{
                    idea = ideas[i];
                    pm = idea.pm;
                    m = i;
                }
            }
            else
			{
                if(ideas[i].time < idea.time)
				{
                    idea = ideas[i];
                    pm = idea.pm;
                    m = i;
                }
            }
        }
    }
    return m;
}
int main(void){
    int pm_num, worker_num, idea_num;

    cin>>pm_num>>worker_num>>idea_num;
    Idea ideas[3000];
    Idea* workers[3000];
    int i;

    for(i=0;i<idea_num;i++)
	{
        Idea idea;
        cin>>idea.pm>>idea.time>>idea.level>>idea.cost;
        idea.num = i;
        ideas[i] = idea;
    }

    for(i=0;i<worker_num;i++)
	{
        workers[i] = nullptr;
    }
    int works = idea_num;
    for(int time = 1;time<=3000,works>0;time++)
	{
        for(i=0;i<worker_num;i++){
            if(workers[i] != nullptr)
			{
                workers[i]->cost = workers[i]->cost -1;
                if(workers[i]->cost <= 0)
				{
                    workers[i]->end_time = time;
                    workers[i]= nullptr;
                    works--;
                };
            }
        }

        for(i=0;i<worker_num;i++)
		{
            if(workers[i] == nullptr) 
			{
                int m = find_work(ideas,idea_num,time);
                if(m>=0)
				{
                    workers[i]=&ideas[m];
                    ideas[m].worker = i+1;
                }
            }

        }
    }
    for(i=0;i<idea_num;i++)
	{
        cout<<ideas[i].end_time<<endl;
    }
}