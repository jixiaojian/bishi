#include <cstdio>  
#include <vector>  
#include <algorithm>  
#include <xfunctional>  
using namespace std;  
void PrintfVectorInt(vector<int> &vet)  
{  
    for (vector<int>::iterator pos = vet.begin(); pos != vet.end(); pos++)  
        printf("%d ", *pos);  
    putchar('\n');  
}  
int heap()  
{  
    const int MAXN = 20;  
    int a[MAXN];  
    int i;  
    for (i = 0; i < MAXN; ++i)  
        a[i] = rand() % (MAXN * 2);  
	int b[] = {50,36,66,76,95,12,25,36};
    //��̬����vector ����vector����  
    vector<int> *pvet = new vector<int>(40); 
	//pvet->assign(a, a + sizeof(a)/4);
    pvet->assign(b, b + sizeof(b)/4);  
  
	//make_heap(_First, _Last, _Comp)
	//Ĭ���ǽ������ѵġ���int���ͣ������ڵ�������������greater<int>()�õ���С�ѡ�
    make_heap(pvet->begin(), pvet->end(),greater<int>());  //greater��less��ͷ�ļ�<xfunctional>�ж���������ṹ��
    PrintfVectorInt(*pvet);  
  
    //���������� ���������м��룬�ٵ���push_heap()  
    pvet->push_back(10);  
    push_heap(pvet->begin(), pvet->end(),greater<int>());  //Ĭ�ϴ����
    PrintfVectorInt(*pvet);  
  
    //ɾ������  Ҫ�ȵ���pop_heap()������������ɾ��  
    pop_heap(pvet->begin(), pvet->end(),greater<int>());  
    pvet->pop_back();   // vector ɾ��ĩβԪ��
    pop_heap(pvet->begin(), pvet->end(),greater<int>());  
    pvet->pop_back();  
    PrintfVectorInt(*pvet);  
  
    //������  
    sort_heap(pvet->begin(), pvet->end(),greater<int>());  //С���������Ϊ�ݼ����飬����������Ϊ�������顣�����Ͳ����Ƕ���
    PrintfVectorInt(*pvet);  
  
    delete pvet;  
    return 0;  
}  