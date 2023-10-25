#include <bits/stdc++.h> 
/*Memoization TC=O(n*w) SC=O(n*w)+O(n)
int find(int i,int maxWeight,vector<int> &weight, vector<int> &value,vector<vector<int>> &dp)//find(3,8) means till index 3 what is the maximum value you can get with maxweight as 8
{
	if(i==0)
	{
		if(weight[0]<=maxWeight)//if first item has less weight than maxweight take it !
			return value[0];
		else
			return 0;
	}
	if(dp[i][maxWeight]!=-1)return dp[i][maxWeight];
	int not_take=find(i-1,maxWeight,weight,value,dp);
	int take=0;//instead of take =0 keep it as INT_MIN so that take case is not considered
	if(weight[i]<=maxWeight)
		take=value[i]+find(i-1,maxWeight-weight[i],weight,value,dp);
	return dp[i][maxWeight]=max(take,not_take);
}
*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	//vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	//return find(n-1,maxWeight,weight,value,dp);

	/*Tabulation TC=O(n*w) Sc=O(n*w)
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int j=0;j<=maxWeight;j++)
	{
		if(weight[0]<=j)
			dp[0][j]=value[0];
		else
			dp[0][j]=0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=maxWeight;j++)
		{
			int not_take=dp[i-1][j];
			int take=0;//instead of take =0 keep it as INT_MIN so that take case is not considered
			if(weight[i]<=j)
				take=value[i]+dp[i-1][j-weight[i]];
			dp[i][j]=max(take,not_take);
		}
	}
	return dp[n-1][maxWeight];
	*/
	/*space optimization TC=O(n*w) SC=O(w)+O(w)-two 1D vectors
	vector<int> dp(maxWeight+1,0);
	vector<int> dummy(maxWeight+1,0);
	for(int j=0;j<=maxWeight;j++)
	{
		if(weight[0]<=j)
			dummy[j]=value[0];
		else
			dummy[j]=0;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=maxWeight;j++)
		{
			int not_take=dummy[j];
			int take=0;//instead of take =0 keep it as INT_MIN so that take case is not considered
			if(weight[i]<=j)
				take=value[i]+dummy[j-weight[i]];
			dp[j]=max(take,not_take);
		}
		dummy=dp;
	}
	return dummy[maxWeight];
	*/

	//space optimization TC=O(n*w) SC=O(w)-one 1D vectors
	vector<int> dp(maxWeight+1,0);
	for(int j=0;j<=maxWeight;j++)
	{
		if(weight[0]<=j)
			dp[j]=value[0];
		else
			dp[j]=0;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=maxWeight;j>=0;j--)//o to maxweight dont work bc overwritten
		{
			int not_take=dp[j];
			int take=0;//instead of take =0 keep it as INT_MIN so that take case is not considered
			if(weight[i]<=j)
				take=value[i]+dp[j-weight[i]];
			dp[j]=max(take,not_take);
		}
	}
	return dp[maxWeight];

}
