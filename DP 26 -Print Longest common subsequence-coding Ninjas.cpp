#include<bits/stdc++.h>
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	//tabulation TC=O(n*m),SC=O(n*m)
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
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else	
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int len=dp[n][m];
	string res="";
	for(int i=0;i<len;i++)
		res+='$';
	int i=n,j=m,index=len-1;
	while(i>0&&j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			res[index]=s1[i-1];
			index--;
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	return res;

}
