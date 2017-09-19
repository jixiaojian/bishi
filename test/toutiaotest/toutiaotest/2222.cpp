#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 500005
//�ڶ���
/* ָ����������С�Ӽ���
 * ���ϰ���˳��,������������;
 * ����:ʹ������������С����������Ԫ��֮�͵ĳ˻����,�ҳ����������˻�,��Ҫ�������������
 * ÿ��Ԫ�ش�С0-100
 * �������n,nΪ0-500000
 * ��������
 * 3
 * 6 1 2
 * ���36*/
int n;
int d[500001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
    }

    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        int middle = d[i];//�ѵ�ǰֵ��Ϊ���������е���Сֵ
        int sum = d[i];
        for (int j = i + 1; j < n; ++j)//��������
        {
			if(middle <= d[j])       //�ȵ�ǰֵ�����
				sum += d[j];
			else
				break;			
		}
        for (int j = i - 1;  j >= 0; --j)//��������
		{
			if(middle <= d[j])      //�ȵ�ǰֵ�����
				sum += d[j];
			else
				break;
		}
            
        ans = max(ans, middle * sum);
    }
    cout << ans << endl;

    return 0;
}
