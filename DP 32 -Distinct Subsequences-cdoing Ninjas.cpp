#include<bits/stdc++.h>
long int mod=1e9+7;
/*Recursion -TC=exponential=O(2^n*2^m) SC=O(n+m)
int find(int i,int j,string &str, string &sub)
{
	if(j<0)
		return 1;
	if(i<0)
		return 0;
	if(str[i]==sub[j])
		return find(i-1,j-1,str,sub)+find(i-1,j,str,sub);
	else
		return find(i-1,j,str,sub);
}
*/
/*DP-Memoization TC=O(n*m) SC=O(n*m)+O(n+m)
int find(int i,int j,string &str, string &sub,vector<vector<int>> &dp)
{
	if(j<0)
		return 1;
	if(i<0)
		return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(str[i]==sub[j])
		return dp[i][j]=(find(i-1,j-1,str,sub,dp)+find(i-1,j,str,sub,dp))%mod;
	else
		return dp[i][j]=(find(i-1,j,str,sub,dp))%mod;
}
*/
int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n=str.size();
	int m=sub.size();
	//vector<vector<int>> dp(n,vector<int>(m,-1));
	//return find(n-1,m-1,str,sub,dp);

	/*Tabulation we need to increase index TC=O(n*m) SC=O(n*m)
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	for(int j=1;j<=m;j++)
		dp[0][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(str[i-1]==sub[j-1])
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
			else
				dp[i][j]=dp[i-1][j]%mod;
		}
	}
	return dp[n][m];
	*/

	/*Space optimization TC=O(n*m) SC=O(m)+O(m)
	vector<int> prev(m+1,0);
	vector<int> dp(m+1,0);
	for(int j=1;j<=m;j++)
		prev[j]=0;
	prev[0]=1;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(str[i-1]==sub[j-1])
				dp[j]=(prev[j-1]+prev[j])%mod;
			else
				dp[j]=prev[j]%mod;
		}
		prev=dp;
	}
	return prev[m];
	*/

	//Space optimization TC=O(n*m) SC=O(m)
	//same as knapsack
	vector<int> dp(m+1,0);
	for(int j=1;j<=m;j++)
		dp[j]=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(str[i-1]==sub[j-1])
				dp[j]=(dp[j-1]+dp[j])%mod;
			
		}
	}
	return dp[m];
}
