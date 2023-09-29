#include<bits/stdc++.h>
/*DP -Top DOwn TC =O(nk) SC=O(n)
int find(int i, int k, vector<int> &height,vector<int> &dp)
{
    if(i==0)return 0;
    if(dp[i]!=-1) return dp[i];
    int m=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(i-j>=0)
            m=min(m,find(i-j,k,height,dp)+abs(height[i]-height[i-j]));
    }
    return dp[i]=m;
}
*/
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
    //return find(n-1,k,height,dp);
    //DP -Bottom Up TC-O(nk) sc=O(n)
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
      int m=INT_MAX;
      for (int j = 1; j <= k; j++) 
      {
        if(i-j>=0)
            m=min(m,dp[i-j]+abs(height[i]-height[i-j]));
      }
      dp[i]=m;
    }
    return dp[n-1];
}
