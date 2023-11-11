#include<bits/stdc++.h>
/*Recursion TC=O(2^n) exponential Sc=O(n)
int find(int i,int buy,vector<int> &prices,int n)
{
    int profit=0;
    if(i>=n) return 0;
    if(buy)
    {
        profit=max(-prices[i]+find(i+1,0,prices,n),find(i+1,1,prices,n)); //buy the stock (- sign cuz profit=sell-buy) and move to next index where u cant buy or directly move to next index where u can still buy
    }
    else
    {
        profit=max(prices[i]+find(i+2,1,prices,n),find(i+1,0,prices,n));//sell on present day and move to nextday+1 where u can buy again or move to next day directly where u can sell
    }
    return profit;
}
*/

/*Dp-Memoization TC=O(n*2) sc=O(n*2)+O(n)
int find(int i,int buy,vector<int> &prices,int n,vector<vector<int>> &dp)
{
    int profit=0;
    if(i>=n) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy)
    {
        profit=max(-prices[i]+find(i+1,0,prices,n,dp),find(i+1,1,prices,n,dp)); //buy the stock (- sign cuz profit=sell-buy) and move to next index where u cant buy or directly move to next index where u can still buy
    }
    else
    {
        profit=max(prices[i]+find(i+2,1,prices,n,dp),find(i+1,0,prices,n,dp));//sell on present day and move to nextday+1 where u can buy again or move to next day directly where u can sell
    }
    return dp[i][buy]=profit;
}
*/

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    //vector<vector<int>> dp(n,vector<int>(2,-1)); 
    //return find(0,1,prices,n,dp);

    /*Dp-Tabulation TC=O(n*2) SC=O(n*2)
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            if(j==1)
            {
                dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }
            else
            {
                dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
    */

    /*rewrite above without using for loop : TC=O(n) SC=O(n*2)
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]); //j==1
        dp[i][0]=max(prices[i]+dp[i+2][1],dp[i+1][0]); //j==0
    }
    return dp[0][1];
    */

    //Space optimization TC=O(n) Sc=O(2+2+2)
    vector<int> curr(2,0);
    vector<int> next1(2,0);
    vector<int> next2(2,0);
    for(int i=n-1;i>=0;i--)
    {
        curr[1]=max(-prices[i]+next1[0],next1[1]); //j==1
        curr[0]=max(prices[i]+next2[1],next1[0]); //j==0

        next2=next1;
        next1=curr;
    }
    return curr[1];
}
