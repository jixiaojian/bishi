/*题目如下：一个nxm的阵列，每个位置上都有一个值，我们从左上角开始出发，向右下方向步进，最终到达右下角，找到我们经过的路径上的值的和的最大值。例如途中的最大值为53，路径经过数字为红色字体。
1	10	3	8
12	2	9	6
5	7	4	11
3	7	16	5
解题思路：
这道题是一个动态规划的问题，从(0,0)这个点开始，将求解数组中到达某一个点的路径最大值（经过路径元素之和）视为一个状态，状态转移方程如下
S[i][j]=A[i][j] + max(S[i+1][j] ; S[i][j+1])
要想获得最优解，路径移动方向为该点下方或者右方的最大路径值较大的一个方向，通过不断递归移动和计算，最终会到达右下方的点。
这里需要用到一个二维数组来记录源数组中每个元素最大路径值，另外需要注意最后一行和最后一列的状态转移方程，和前面的通式略有不同：
S[i][j]=A[i][j] + S[i][j+1]
S[i][j]=A[i][j] + S[i+1][j]
*/
#include <iostream>
using namespace std;

int a[10][10]={0};    //源数组
int maxpath[10][10];  //存放从a[i,j]开始达到右下方的最大路径

int DP()
{   //行列变量定义和函数声明
    int row,col;
    int i,j;
    int getMaxPath(int i,int j,int n,int m);

    //数据赋初值
    cin>>row>>col;
    for(i=0;i<row;++i)
        for(j=0;j<col;++j)
            cin>>a[i][j];

    for(i=0;i<row;++i)
        for(j=0;j<col;++j)
           maxpath[i][j]=-1;

    maxpath[0][0]=getMaxPath(0,0,row-1,col-1);
    cout<<"结果"<<maxpath[0][0]<<endl;

    //数据输出部分（调试用）
    cout<<"源数组："<<endl;
    for(i=0;i<row;++i)
    {
         for(j=0;j<col;++j)
            cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    cout<<"最大路径数组："<<endl;
    for(i=0;i<row;++i)
    {
         for(j=0;j<col;++j)
            cout<<maxpath[i][j]<<'\t';
         cout<<endl;
    }
    return 0;
}

int getMaxPath(int i,int j,int n,int m) //以a[i,j]为起点
{
    if(i==n&&j==m)
        return a[i][j];
    if(i==n)        //最后一行
    {
        if(maxpath[i][j+1]==-1)
            maxpath[i][j+1]=getMaxPath(i,j+1,n,m);//向右走
        return a[i][j]+maxpath[i][j+1];
    }
    if(j==m)      //最后一列
    {
        if(maxpath[i+1][j]==-1)
            maxpath[i+1][j]=getMaxPath(i+1,j,n,m);//向下走
        return a[i][j]+maxpath[i+1][j];
    }
    if(maxpath[i][j+1]==-1)
        maxpath[i][j+1]=getMaxPath(i,j+1,n,m);   //向右走
    if(maxpath[i+1][j]==-1)
        maxpath[i+1][j]=getMaxPath(i+1,j,n,m);   //向下走
    return a[i][j]+(maxpath[i][j+1]>maxpath[i+1][j]?maxpath[i][j+1]:maxpath[i+1][j]);
}