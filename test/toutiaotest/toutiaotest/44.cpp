#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 500010;  
typedef pair<int, int> Dot;
Dot dot[maxn];
int maps[maxn], tmp[maxn], N;
int bit[maxn];
vector<Dot> result;

void smallify()
{
    int diff_cnt = 0;

    for(int i = 0; i < N; i++)
        tmp[i] = dot[i].second;
    sort(tmp, tmp + N);

    for(int i = 0; i < N; i++) 
	{
        if(i > 0 && tmp[i] == tmp[i - 1]) 
			continue;
        maps[tmp[i]] = diff_cnt++;
    }

    for(int i = 0; i < N; i++) {
        tmp[i] = maps[dot[i].second];
    }
}

inline int lowbit(int x)
{
    return x & -x;
}

void Add(int pos, int n)
{
    while(pos <= N) 
	{
        bit[pos] += n;
        pos += lowbit(pos);
    }
}

int Sum(int pos)
{
    int sum = 0;
    while(pos > 0) {
        sum += bit[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &dot[i].first, &dot[i].second);

    sort(dot, dot + N);
    smallify();
    memset(bit, 0, sizeof(bit));

    int cnt = 0;
    for(int i = N - 1; i >= 0; i--) 
	{
        if(i < N - 1 && dot[i].first != dot[i + 1].first) 
		{
            for(int j = i + 1; j < N && dot[j].first == dot[j + 1].first; j++, cnt++)
                Add(tmp[j] + 1, 1);
        }
        if(Sum(tmp[i]) == cnt)
            result.push_back(Dot(dot[i].first, dot[i].second));
    }
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
        printf("%d %d\n", result[i].first, result[i].second);
  
    return 0;
}