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
    //动态申请vector 并对vector建堆  
    vector<int> *pvet = new vector<int>(40); 
	//pvet->assign(a, a + sizeof(a)/4);
    pvet->assign(b, b + sizeof(b)/4);  
  
	//make_heap(_First, _Last, _Comp)
	//默认是建立最大堆的。对int类型，可以在第三个参数传入greater<int>()得到最小堆。
    make_heap(pvet->begin(), pvet->end(),greater<int>());  //greater和less是头文件<xfunctional>中定义的两个结构。
    PrintfVectorInt(*pvet);  
  
    //加入新数据 先在容器中加入，再调用push_heap()  
    pvet->push_back(10);  
    push_heap(pvet->begin(), pvet->end(),greater<int>());  //默认大根堆
    PrintfVectorInt(*pvet);  
  
    //删除数据  要先调用pop_heap()，再在容器中删除  
    pop_heap(pvet->begin(), pvet->end(),greater<int>());  
    pvet->pop_back();   // vector 删除末尾元素
    pop_heap(pvet->begin(), pvet->end(),greater<int>());  
    pvet->pop_back();  
    PrintfVectorInt(*pvet);  
  
    //堆排序  
    sort_heap(pvet->begin(), pvet->end(),greater<int>());  //小根堆排序后为递减数组，大根堆排序后为递增数组。排序后就不再是堆了
    PrintfVectorInt(*pvet);  
  
    delete pvet;  
    return 0;  
}  