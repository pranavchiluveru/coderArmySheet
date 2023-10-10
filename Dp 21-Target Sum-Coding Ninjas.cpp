#include <bits/stdc++.h>
//same as DP 18 -Find subsets with given differnce 
//Top down -TC=O(n*k) SC=O(n*k)+O(n)
//we can write bottom up and space optimization also
int find(int i,int k,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(arr[0]==0&&k==0)return 2;
        if(k==0)return 1;
        if(arr[0]==k)return 1;
        return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    int not_take=find(i-1,k,arr,dp);
    int take=0;
    if(arr[i]<=k)
        take=find(i-1,k-arr[i],arr,dp);
    return dp[i][k]=take+not_take;
} 
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int k=sum+target;
    if(k%2!=0)return 0;
    k=k/2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return find(n-1,k,arr,dp);
}
