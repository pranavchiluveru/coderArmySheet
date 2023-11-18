#include <bits/stdc++.h>
void setmatrix(int i,int j,vector<vector<int>> &matrix)
{
	for(int row=0;row<matrix.size();row++)
	{
		if(matrix[row][j]!=0)
		{
				matrix[row][j]=-1;
		}
		
	}
	for(int col=0;col<matrix[0].size();col++)
	{
		if(matrix[i][col]!=0)
		{
				matrix[i][col]=-1;
		}
	}
}
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.//TC=O(n*m*(n+m)) SC=O(1)
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				setmatrix(i,j,matrix);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
    	}
    }
}
