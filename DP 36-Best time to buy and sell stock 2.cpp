#include<bits/stdc++.h>
/*Recursion TC=O(2^n) exponential Sc=O(n)
long find(int i,int buy,long *values,int n)
{
    long profit=0;
    if(i==n) return 0;
    if(buy)
    {
        profit=max(-values[i]+find(i+1,0,values,n),find(i+1,1,values,n)); //buy the stock (- sign cuz profit=sell-buy) and move to next index where u cant buy or directly move to next index where u can still buy
    }
    else
    {
        profit=max(values[i]+find(i+1,1,values,n),find(i+1,0,values,n));//sell on present day and move to next day where u can buy again or move to next day directly where u can sell
    }
    return profit;
}
*/

/*Dp-Memoization TC=O(n*2) sc=O(n*2)+O(n)
long find(int i,int buy,long *values,int n,vector<vector<long>> &dp)
{
    long profit=0;
    if(i==n) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy)
    {
        profit=max(-values[i]+find(i+1,0,values,n,dp),find(i+1,1,values,n,dp)); //buy the stock (- sign cuz profit=sell-buy) and move to next index where u cant buy or directly move to next index where u can still buy
    }
    else
    {
        profit=max(values[i]+find(i+1,1,values,n,dp),find(i+1,0,values,n,dp));//sell on present day and move to next day where u can buy again or move to next day directly where u can sell
    }
    return dp[i][buy]=profit;
}
*/
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    //vector<vector<long>> dp(n,vector<long>(2,-1)); //dp[n][buy] buy as 2 values 0,1
    //return find(0,1,values,n,dp); //starting at index 0 with buy =1 means u can buy what is the maximum profit u can get

    /*Dp-Tabulation TC=O(n*2) SC=O(n*2)
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            if(j==1)
            {
                dp[i][j]=max(-values[i]+dp[i+1][0],dp[i+1][1]);
            }
            else
            {
                dp[i][j]=max(values[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
    */

    //Space optimization TC=O(n*2) Sc=O(2+2)
    vector<long> curr(2,0);
    vector<long> next(2,0);
    next[0]=0;
    next[1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            if(j==1)
            {
                curr[j]=max(-values[i]+next[0],next[1]);
            }
            else
            {
                curr[j]=max(values[i]+next[1],next[0]);
            }
        }
        next=curr;
    }
    return curr[1];

}
