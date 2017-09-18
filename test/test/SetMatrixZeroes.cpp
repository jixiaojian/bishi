#include <iostream>
#include <string>
#include <vector>
using namespace std;

void setMatrixZero(vector<vector<int>> &matrix)
{
	vector<vector<int>> zeroIndex;	
	int m = matrix.size();
	int n = matrix[0].size();
	for(int i =0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j] == 0)
			{
				vector<int> onezeroIndex;
				onezeroIndex.push_back(i);
				onezeroIndex.push_back(j);
				zeroIndex.push_back(onezeroIndex);
			}
		}
		for(int c=0;c<zeroIndex.size();c++)
		{			
			int row = zeroIndex[c][0];
			int col = zeroIndex[c][1];
			for(int i = 0;i<m;i++)
				matrix[i][col] = 0;
			for(int j = 0;j<n;j++)
				matrix[row][j] = 0;
		}
}