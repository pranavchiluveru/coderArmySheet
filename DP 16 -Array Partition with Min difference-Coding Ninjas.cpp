#include<bits/stdc++.h>
/* Top Down TLE
bool find(vector<int> &arr,int i,int k,vector<vector<int>> dp)
{
	if(k==0)return true;
	if(i==0)return arr[i]==k;
	if(dp[i][k]!=-1)return dp[i][k];
	bool not_take=find(arr,i-1,k,dp);
	bool take=false;
	if(arr[i]<=k)
		take=find(arr,i-1,k-arr[i],dp);
	return dp[i][k]=take|not_take;
}
*/
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	int k=sum/2;
	/* Top Down-TLE
    while (k > 0)
	{
		vector<vector<int>> dp(n,vector<int>(k+1,-1));
        if(find(arr, n - 1, k,dp)==false)
			k=k-1;
		else
			break;
    }
	int j=sum-k;
	return j-k;
	*/
	//Bottom Up TC=O(n*k)+O(n) SC=O(n*k)// we can also do space optimization
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
			dp[i][j]=take|not_take;
		}
	}
	int m=INT_MAX;
	//check in dp array last row :what does last row signify?
	for(int i=0;i<=k;i++)
	{
		if(dp[n-1][i]==true)
		{
			int subset1_sum=i;
			int subset2_sum=sum-i;
			int diff=abs(subset1_sum-subset2_sum);
			m=min(m,diff);
		}
	}
	return m;
	

}
