#include <bits/stdc++.h> 
/*Top Down -TC=O(n*n) SC=O(n*n)+O(n)
int find(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp)
{
	if(row==n-1)return triangle[n-1][col];
	if(dp[row][col]!=-1)return dp[row][col];
	return dp[row][col]=triangle[row][col]+min(find(row+1,col,n,triangle,dp),find(row+1,col+1,n,triangle,dp));
}
*/

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	//vector<vector<int>> dp(n,vector<int>(n,-1));
	//return find(0,0,n,triangle,dp);

	/*Bottom Up -TC=O(n*n) SC=O(n*n)
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==n-1)
			{
				dp[i][j]=triangle[i][j];
			}
			else
			{
				dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
			}
		}
	}
	return dp[0][0];
	*/
	//space optimization TC=O(n*n) SC=O(n)
	vector<int> dummy(n,0);
	vector<int> dp(n);
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==n-1)
			{
				dp[j]=triangle[i][j];
			}
			else
			{
				dp[j]=triangle[i][j]+min(dummy[j],dummy[j+1]);
			}
		}
		dummy=dp;
	}
	return dummy[0];
}
