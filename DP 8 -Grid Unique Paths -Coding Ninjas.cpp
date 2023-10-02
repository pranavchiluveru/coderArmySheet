#include <bits/stdc++.h> 
/*
//Recursion TC=O(2^m*n) SC=O(path length)=O(m-1+n-1)
//DP-Top Down TC=O(m*n) SC=dp vector+stack=O(m*n)+O(m+n)
int find(int i,int j,vector<vector<int>> &dp)
{
	if(i==0&&j==0)return 1;
	if(i<0 || j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	return dp[i][j]=find(i-1,j,dp)+find(i,j-1,dp);
}
*/
int uniquePaths(int m, int n) {
	// Write your code here.
	//vector<vector<int>> dp(m,vector<int> (n,-1));
	//return find(m-1,n-1,dp);

	/*Bottom Up -TC=O(m*n) SC=O(m*n)
	vector<vector<int>> dp(m,vector<int> (n));
	dp[0][0]=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0&&j==0)
				dp[i][j]=1;
            else 
			{  
				int up=0,left=0;
		    	if(i>0)
					up=dp[i-1][j];
				if(j>0)
					left=dp[i][j-1];
				dp[i][j]=up+left;
            }
        }
	}
	return dp[m-1][n-1];

	*/
	//space optimization Tc=O(m*n) SC=O(n)
	vector<int> dummy(n,0);
	vector<int> dp(n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0&&j==0) dp[j]=1;
            else 
			{
				int left=0;
	          	if (j > 0)
                	left = dp[j - 1];
				dp[j]=dummy[j]+left;

            }
        }
		dummy=dp;
	}
	return dummy[n-1];
}
