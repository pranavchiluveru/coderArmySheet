#include<bits/stdc++.h>
/*Recursion TC=O(2^n*2^m)
int find(int i,int j,string &s, string &t)
{
	if(i<0||j<0)return 0;
	if(s[i]==t[j])//match
		return 1+find(i-1,j-1,s,t);
	return max(find(i-1,j,s,t),find(i,j-1,s,t));//not match
}
*/
/*Memoization TC=O(n*m) SC=O(n*m) for dp + O(n+m) stack space take ab|cd we get recursion take depth is 4(2+2) for alternate deletions
int find(int i,int j,string &s, string &t,vector<vector<int>> &dp)
{
	if(i<0||j<0)return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s[i]==t[j])//match
		return dp[i][j]=1+find(i-1,j-1,s,t,dp);
	return dp[i][j]=max(find(i-1,j,s,t,dp),find(i,j-1,s,t,dp));//not match
}
*/
int lcs(string s, string t)
{
	//Write your code here
	int n=s.size();
	int m=t.size();
	//vector<vector<int>> dp(n,vector<int>(m,-1));
	//return find(n-1,m-1,s,t,dp);	

	/*Tabulation TC=O(n*m) SC=(n*m)
	for tabulation do shifting of index from 0 -n-1 to 1 to n so that its easy to write  base case 
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int j=0;j<=m;j++)
	{
		dp[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else	
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
	*/

	//Space optimization TC=O(n*m) SC=O(m)
	vector<int> prev(m+1,0);
	vector<int> curr(m+1,0);
	for(int i=0;i<=m;i++)
	{
		prev[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])
				curr[j]=1+prev[j-1];
			else	
				curr[j]=max(prev[j],curr[j-1]);
		}
		prev=curr;
	}
	return prev[m];

}
