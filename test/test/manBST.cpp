/*一棵满二叉排序树深度为k，节点数为2^k-1;节点值为1至（2^k - 1）,给出k和任意三个节点的值，输出包含该三个节点的最小子树的根节点。
样例输入：4 10 15 13
样例输出：12*/
//要解决满二叉排序树三个节点的最小子树的根节点这个问题可以得到如下几点： 
//1. 无须建立二叉树，从1~(2^k-1)的递增数组即就是一个满二叉排序树的中序遍历的结果 
//2. 当输入的三个元素在二分节点两侧时，当前的二分节点就是要查找的最小子树的根节点（根据这个规则，我们也无需判断三个元素，只需判断最大元素和最小元素的位置即可） 
#include <iostream>
#include <vector>
using namespace std;

int searchroot()
{
	int k,k1,k2,k3;
	cin>>k>>k1>>k2>>k3;
	int n = pow(2,k) - 1;
	int MIN = min(min(k1,k2),k3);
	int MAX = max(max(k1,k2),k3);
	int i = 1;
	int j = n;
	while(i <  j)
	{
		int mid = (i + j)/2;
		if(MIN < mid && MAX > mid)
			return mid;
		else if(MAX < mid)
			j = mid - 1;
		else if(MIN >mid)
			i = mid + 1;		
	}
}