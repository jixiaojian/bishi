
#include <iostream>
#include <numeric>
#include <limits>
using namespace std;
// ������������������ʵ����ĿҪ��Ĺ���
// ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^
//��n�����������ܺ�
int result(int x, int y) 
{
    if(y == 1 || y == 2)
       return 2*y;
    if(y == 3)
       return 8;
    if(y <= x)
    {
		int i = 2;
		int s = y;
		while(s>=1)
		{
			s = s-i;
			y+=s;
			i++;
		}
		y = 2*y;
    }
    return 0;
}
int main() {
    int x, y;
    cin >> x;
    cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
    cin >> y;
    cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
    int res = result(x,y);
    cout << res << endl;
    return 0;
}