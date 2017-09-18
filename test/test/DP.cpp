/*��Ŀ���£�һ��nxm�����У�ÿ��λ���϶���һ��ֵ�����Ǵ����Ͻǿ�ʼ�����������·��򲽽������յ������½ǣ��ҵ����Ǿ�����·���ϵ�ֵ�ĺ͵����ֵ������;�е����ֵΪ53��·����������Ϊ��ɫ���塣
1	10	3	8
12	2	9	6
5	7	4	11
3	7	16	5
����˼·��
�������һ����̬�滮�����⣬��(0,0)����㿪ʼ������������е���ĳһ�����·�����ֵ������·��Ԫ��֮�ͣ���Ϊһ��״̬��״̬ת�Ʒ�������
S[i][j]=A[i][j] + max(S[i+1][j] ; S[i][j+1])
Ҫ�������Ž⣬·���ƶ�����Ϊ�õ��·������ҷ������·��ֵ�ϴ��һ������ͨ�����ϵݹ��ƶ��ͼ��㣬���ջᵽ�����·��ĵ㡣
������Ҫ�õ�һ����ά��������¼Դ������ÿ��Ԫ�����·��ֵ��������Ҫע�����һ�к����һ�е�״̬ת�Ʒ��̣���ǰ���ͨʽ���в�ͬ��
S[i][j]=A[i][j] + S[i][j+1]
S[i][j]=A[i][j] + S[i+1][j]
*/
#include <iostream>
using namespace std;

int a[10][10]={0};    //Դ����
int maxpath[10][10];  //��Ŵ�a[i,j]��ʼ�ﵽ���·������·��

int DP()
{   //���б�������ͺ�������
    int row,col;
    int i,j;
    int getMaxPath(int i,int j,int n,int m);

    //���ݸ���ֵ
    cin>>row>>col;
    for(i=0;i<row;++i)
        for(j=0;j<col;++j)
            cin>>a[i][j];

    for(i=0;i<row;++i)
        for(j=0;j<col;++j)
           maxpath[i][j]=-1;

    maxpath[0][0]=getMaxPath(0,0,row-1,col-1);
    cout<<"���"<<maxpath[0][0]<<endl;

    //����������֣������ã�
    cout<<"Դ���飺"<<endl;
    for(i=0;i<row;++i)
    {
         for(j=0;j<col;++j)
            cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    cout<<"���·�����飺"<<endl;
    for(i=0;i<row;++i)
    {
         for(j=0;j<col;++j)
            cout<<maxpath[i][j]<<'\t';
         cout<<endl;
    }
    return 0;
}

int getMaxPath(int i,int j,int n,int m) //��a[i,j]Ϊ���
{
    if(i==n&&j==m)
        return a[i][j];
    if(i==n)        //���һ��
    {
        if(maxpath[i][j+1]==-1)
            maxpath[i][j+1]=getMaxPath(i,j+1,n,m);//������
        return a[i][j]+maxpath[i][j+1];
    }
    if(j==m)      //���һ��
    {
        if(maxpath[i+1][j]==-1)
            maxpath[i+1][j]=getMaxPath(i+1,j,n,m);//������
        return a[i][j]+maxpath[i+1][j];
    }
    if(maxpath[i][j+1]==-1)
        maxpath[i][j+1]=getMaxPath(i,j+1,n,m);   //������
    if(maxpath[i+1][j]==-1)
        maxpath[i+1][j]=getMaxPath(i+1,j,n,m);   //������
    return a[i][j]+(maxpath[i][j+1]>maxpath[i+1][j]?maxpath[i][j+1]:maxpath[i+1][j]);
}