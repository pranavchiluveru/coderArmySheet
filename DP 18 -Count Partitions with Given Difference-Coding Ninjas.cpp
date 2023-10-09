#include <bits/stdc++.h> 
int mod=1e9+7;
/*Top down Solution -TC=O(n*k) SC=O(n*k)+O(n)
int find(int i,int k,vector<int> &arr,vector<vector<int>> &dp)
{
    //here we are going till base case because elements have 0 included in previous examples we had 1<=elements<=n
    if(i==0)
    {
        if(k==0 && arr[i]==0) return 2;//take or not_take k=0 only
        if(k==0)return 1;
        if(k==arr[i])return 1;//we take it
        return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    int not_take=find(i-1,k,arr,dp);
    int take=0;
    if(arr[i]<=k)
        take=find(i-1,k-arr[i],arr,dp);
    return dp[i][k]=(take+not_take)%mod;
}*/

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    /*
    s1+s2=sum
    s1-s2=d
    2s1=sum+d
    s1=(sum+d)/2
    */
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if((sum+d)%2!=0)return 0;
    int k=(sum+d)/2;
    //vector<vector<int>> dp(n,vector<int>(k+1,-1));
    //return find(n-1,k,arr,dp);
    /*Bottom Up -TC=O(n*k) SC=O(n*k)
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    if(arr[0]==0)dp[0][0]=2;//i==0 and k==0
    else dp[0][0]=1;
    if(arr[0]!=0)dp[0][arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(arr[i]<=j)
                take=dp[i-1][j-arr[i]];
            dp[i][j]=(take+not_take)%mod;
        }
    }
    return dp[n-1][k];
    */
    //space optimization TC=O(n*k) SC=O(n)
    vector<int> dummy(k+1,0);
    vector<int> dp(k+1);
    if(arr[0]==0)dummy[0]=2;//i==0 and k==0
    else dummy[0]=1;
    if(arr[0]!=0)dummy[arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int not_take=dummy[j];
            int take=0;
            if(arr[i]<=j)
                take=dummy[j-arr[i]];
            dp[j]=(take+not_take)%mod;
        }
        dummy=dp;
    }
    return dummy[k];
}


