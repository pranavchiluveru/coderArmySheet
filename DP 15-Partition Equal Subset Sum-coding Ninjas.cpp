#include<bits/stdc++.h>
/*Top Down TC=(n*k) SC=O(n*k)+O(n) 
bool find(vector<int> &arr,int i,int k,vector<vector<int>> &dp)
{
	if(k==0) return true;
	if(i==0) return arr[i]==k;
	if(dp[i][k]!=-1)return dp[i][k];
	bool not_take=find(arr,i-1,k,dp);
	bool take=false;
	if(arr[i]<=k)
		take=find(arr,i-1,k-arr[i],dp);
	return dp[i][k]=take| not_take;
}
*/
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	//if sum is odd then we cant divide into 2 subsets of equal sum
	if(sum%2!=0)return false;
	int k=sum/2;
	/*Top Down
	find any subsquence with sum
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return find(arr,n-1,k,dp);
	*/
	/*Bottom Up TC=O(n*k) SC=O(n*k)
	vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	for(int i=0;i<n;i++)
		dp[i][0]=true;
	dp[0][arr[0]]=true;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			bool not_take=dp[i-1][j];
			bool take=false;
			if(arr[i]<=j)
				take=dp[i-1][j-arr[i]];
			dp[i][j]=take| not_take;
		}
	}
	return dp[n-1][k];
	*/
	//Space optimization TC=O(n*k) SC=O(n*k)
	vector<bool> dummy(k+1,0);
	vector<bool> dp(k+1);
	dummy[0]=true;dp[0]=true;
	dummy[arr[0]]=true;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			bool not_take=dummy[j];
			bool take=false;
			if(arr[i]<=j)
				take=dummy[j-arr[i]];
			dp[j]=take| not_take;
		}
		dummy =dp;
	}

	return dummy[k];

}
