#include<bits/stdc++.h>
/*Recursion TC=exponential SC=O(n)
int find(int i,int buy,int n,vector<int> &prices, int fee)
{
	if(i==n)return 0;
	if(buy)
	{
		return max(-prices[i]+find(i+1,0,n,prices,fee),find(i+1,1,n,prices,fee));
	}
	return max(prices[i]-fee+find(i+1,1,n,prices,fee),find(i+1,0,n,prices,fee));
}
*/

/*DP -Memoization TC=O(n*2) SC=O(n*2)+O(n)
int find(int i,int buy,int n,vector<int> &prices, int fee,vector<vector<int>> &dp)
{
	if(i==n)return 0;
	if(dp[i][buy]!=-1)return dp[i][buy];
	if(buy)
	{
		return dp[i][buy]=max(-prices[i]+find(i+1,0,n,prices,fee,dp),find(i+1,1,n,prices,fee,dp));
	}
	return dp[i][buy]=max(prices[i]-fee+find(i+1,1,n,prices,fee,dp),find(i+1,0,n,prices,fee,dp));
}
*/
int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	//vector<vector<int>> dp(n,vector<int>(2,-1));
	//return find(0,1,n,prices,fee,dp);

	/*Dp-Tabulation TC=O(n) Sc=O(n*2)
	vector<vector<int>> dp(n+1,vector<int>(2,0));
	for(int i=n-1;i>=0;i--)
	{
		dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
		dp[i][0]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
	}
	return dp[0][1];
	*/

	//Space optimization TC=O(n) SC=O(4)
	vector<int> curr(2,0);
	vector<int> next(2,0);
	for(int i=n-1;i>=0;i--)
	{
		curr[1]=max(-prices[i]+next[0],next[1]);
		curr[0]=max(prices[i]-fee+next[1],next[0]);
		next=curr;
	}
	return next[1];

}
