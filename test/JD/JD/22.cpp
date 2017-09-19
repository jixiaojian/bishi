#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//�������� 242�������Ϊ{2��2}��{4}��������Ӻ����
bool check(int n) 
{
    char s[11];
    int cur = 0, t = 0;
   //��һ�������룺����ʮ���١�ǧ����������s[i]��Ȼ�����
	while(n > 0) 
	{
        s[cur] = n % 10;
        t += s[cur++];
        n /= 10;
    }
    if(t % 2) //��Ӻ�Ϊ��������������
		return false;
    t /= 2;  //���ֲ���
    bool ok[42] = {0};
    ok[s[0]] = true;
    for(int i = 1; i < cur; i++) 
	{
        int v = s[i];
        for(int j = 41; j >= 0; j--) //������λ�����Ϊ81(9*9,r<10e9)
		{
            if(ok[j] && j + v <= 41) 
			{
                ok[j + v] = true;
            }
        }
        if(ok[t]) 
		{
            return true;
        }
    }
    return false;
}
int l, r;
int main() 
{
    int res = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++) 
	{
        if(check(i)) 
			res++;
    }
    cout << res << endl;
    return 0;
}
