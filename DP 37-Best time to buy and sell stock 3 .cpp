#include<bits/stdc++.h>
/*Recursion TC=O(2^n)exponential sc=O(n)
int find(int i,int buy,vector<int>& prices,int n,int limit)
{
    int profit=0;
    if(limit==0)return 0;
    if(i==n) return 0;
    if(buy)
    {
        profit=max(-prices[i]+find(i+1,0,prices,n,limit),find(i+1,1,prices,n,limit));
    }
    else
    {
        profit=max(prices[i]+find(i+1,1,prices,n,limit-1),find(i+1,0,prices,n,limit));
    }
    return profit;
}
*/

/*Dp-Memoization TC=O(n*2*2) SC=O(n*2*2)+O(n)
int find(int i,int buy,vector<int>& prices,int n,int limit,vector<vector<vector<int>>> &dp)
{
    int profit=0;
    if(limit==0||i==n)return 0;
    if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];
    if(buy)
    {
        profit=max(-prices[i]+find(i+1,0,prices,n,limit,dp),find(i+1,1,prices,n,limit,dp));
    }
    else
    {
        profit=max(prices[i]+find(i+1,1,prices,n,limit-1,dp),find(i+1,0,prices,n,limit,dp));
    }
    return dp[i][buy][limit]=profit;
}
*/
int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n=prices.size();
    //vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //return find(0,1,prices,n,2,dp);

    /*DP-Tabulation TC=O(n*2*2) Sc=O(n*2*3)
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            for(int limit=1;limit<=2;limit++)
            {
                if(j==1)
                    dp[i][j][limit]=max(-prices[i]+dp[i+1][0][limit],dp[i+1][1][limit]);
                else
                    dp[i][j][limit]=max(prices[i]+dp[i+1][1][limit-1],dp[i+1][0][limit]);
            }
        }
    }
    return dp[0][1][2];
    */

    //Space optimization TC=O(n*2*2) SC=O(2*3)+O(2*3)
    vector<vector<int>> next(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            for(int limit=1;limit<=2;limit++)
            {
                if(j==1)
                    curr[j][limit]=max(-prices[i]+next[0][limit],next[1][limit]);
                else
                    curr[j][limit]=max(prices[i]+next[1][limit-1],next[0][limit]);
            }
        }
        next=curr;
    }
    return curr[1][2];

    /*Note : there is another method using transaction number B:0,S:1,B=2,S;3 ---->Take DP[n][4]
    int find(int i,int transaction,vector<int>& prices,int n,vector<vector<int>> &dp)
    {
    int profit=0;
    if(transaction==4||i==n)return 0;
    if(dp[i][transaction]!=-1)return dp[i][transaction];
    if(transaction%2==0)
    {
        profit=max(-prices[i]+find(i+1,transaction+1,prices,n,dp),find(i+1,transaction,prices,n,dp));
    }
    else
    {
        profit=max(prices[i]+find(i+1,transaction+1,prices,n,dp),find(i+1,transaction,prices,n,dp));
    }
    return dp[i][transaction]=profit;
    }
    call in main as-->return find(0,0,prices,n,dp);
    --do tabulation and space optimization for this
    */
}
