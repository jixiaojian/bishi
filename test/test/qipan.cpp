#include <iostream>
#include <string>
using namespace std;

int main() 
{
	char a[14]="hello";
	//a = "hello";
	//a[14] = {'h','e','l'};
  while(1) 
  {
    char a[3][3]; //��ά����洢��������
    int xCount = 0, oCount = 0; //X��0�ĸ���
    for(int i = 0; i < 3; ++i) 
	{
      string s = "";
      getline(cin, s);
      if(s.size() == 0) return 0; //��ֹ����
      for(int j = 0; j < 3; ++j) 
	  {
        a[i][j] = s[j]; //��ֵ
        // ����
        if(s[j] == 'X') ++xCount;
        else if(s[j] == '0') ++oCount;
      }
    }
    
    // �����ֵ�ͻ����ж�
    int diff = xCount - oCount;
    if(diff != 0 && diff != 1) 
	{
      cout << "x" << endl;
      continue;
    }
    
    int wx = 0, wo = 0; //XӮ��0Ӯ�ı�־
    // �ж���
    for(int i = 0; i < 3; ++i) 
	{
      if(a[i][1] != '.' && a[i][0] == a[i][1] && a[i][2] == a[i][1]) 
	  {
        if(a[i][1] == 'X') wx = 1;
        else wo = 1;
      }
    }
    // �ж���
    for(int i = 0; i < 3; ++i) 
	{
      if(a[1][i] != '.' && a[0][i] == a[1][i] && a[2][i] == a[1][i]) 
	  {
        if(a[1][i] == 'X') wx = 1;
        else wo = 1;
      }
    }
    // �ж϶Խ�
    if(a[1][1] != '.' && ((a[0][0] == a[1][1] && a[2][2] == a[1][1]) || (a[0][2] == a[1][1] && a[2][0] == a[1][1]))) 
	{
      if(a[1][1] == 'X') wx = 1;
      else wo = 1;
    }
    
    // �ж����
    if(wx && wo || wx && !diff || wo && diff) cout << "x" << endl; //X��0����ͬʱӮ��XӮʱdiff����Ϊ0��0Ӯʱdiff����Ϊ1
    else if(wx) cout << "1 won" << endl;
    else if(wo) cout << "2 won" << endl;
    else if(xCount + oCount == 9) cout << "draw" << endl;
    else if(diff) cout << "2" << endl;
    else if(diff == 0) cout << "1" << endl;
  }
}