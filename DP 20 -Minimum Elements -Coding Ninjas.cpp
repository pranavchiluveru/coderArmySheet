#include <bits/stdc++.h> 
/*Memoization TC=O(i*x) SC=O(i*x)+O(x)
int find(int i,int x,vector<int> &num,vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(x%num[0]==0)
            return x/num[0];
        else
            return 1e9;
        
    }
    if(dp[i][x]!=-1)return dp[i][x];
    int not_take=find(i-1,x,num,dp);
    int take=1e9;
    if(num[i]<=x)
        take=1+find(i,x-num[i],num,dp);
    return dp[i][x]=min(not_take,take);
}
*/

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    //vector<vector<int>> dp(n,vector<int>(x+1,-1));
    //int res=find(n-1,x,num,dp);
    //return (1e9<=res)?-1:res;

    /*Tabulation TC=O(i*x) sc=O(i*x)
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int j=0;j<=x;j++)
    {
        if(j%num[0]==0)
            dp[0][j]=j/num[0];
        else
            dp[0][j]=1e9;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            int not_take=dp[i-1][j];
            int take=1e9;
            if(num[i]<=j)
                take=1+dp[i][j-num[i]];
            dp[i][j]=min(not_take,take);
        }
    }
    return dp[n-1][x]>=1e9?-1:dp[n-1][x];
    */

    //Space optimization TC=O(i*x) sc=O(x)
    vector<int> dummy(x+1,0);
    vector<int> dp(x+1,0);
    for(int j=0;j<=x;j++)
    {
        if(j%num[0]==0)
            dummy[j]=j/num[0];
        else
            dummy[j]=1e9;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            int not_take=dummy[j];
            int take=1e9;
            if(num[i]<=j)
                take=1+dp[j-num[i]];
            dp[j]=min(not_take,take);
        }
        dummy=dp;
    }
    return dummy[x]>=1e9?-1:dummy[x];
}
