#include <bits/stdc++.h> 
/*Method 1*/
/*Method 1-Recursion -TC=exponential sc=O(n)
int find(int i,int buy,int n,int transaction,vector<int> &prices)
{
    int profit=0;
    if(i==n||transaction==0)    return 0;
    if(buy)
    {
        profit=max(-prices[i]+find(i+1,0,n,transaction,prices),find(i+1,1,n,transaction,prices));
    }
    else
    {
        profit=max(prices[i]+find(i+1,1,n,transaction-1,prices),find(i+1,0,n,transaction,prices));
    }
    return profit;
}
*/

/*Method 1-Dp-Memoization TC=O(n*2*k) Sc=O(n*2*k)+O(n)
int find(int i,int buy,int n,int transaction,vector<int> &prices,vector<vector<vector<int>>> &dp)
{
    int profit=0;
    if(i==n||transaction==0)    return 0;
    if(dp[i][buy][transaction]!=-1)return dp[i][buy][transaction];
    if(buy)
    {
        profit=max(-prices[i]+find(i+1,0,n,transaction,prices,dp),find(i+1,1,n,transaction,prices,dp));
    }
    else
    {
        profit=max(prices[i]+find(i+1,1,n,transaction-1,prices,dp),find(i+1,0,n,transaction,prices,dp));
    }
    return dp[i][buy][transaction]=profit;
}
*/

/*Method 2 -Recusion TC=exponential sc=O(n)
int find(int i,int transno,int n,int k,vector<int> &prices)
{
    int profit=0;
    if(i==n||transno==k)return 0;
    if(transno%2==0)
    {
        profit=max(-prices[i]+find(i+1,transno+1,n,k,prices),find(i+1,transno,n,k,prices));
    }
    else
    {
        profit=max(prices[i]+find(i+1,transno+1,n,k,prices),find(i+1,transno,n,k,prices));
    }
    return profit;
}
*/
/*Method 2 -Dp Memoization TC=O(n*k*2) sc=O(n*k*2)+O(n)
int find(int i,int transno,int n,int k,vector<int> &prices,vector<vector<int>> &dp)
{
    int profit=0;
    if(i==n||transno==k)return 0;
    if(dp[i][transno]!=-1) return dp[i][transno];
    if(transno%2==0)
    {
        profit=max(-prices[i]+find(i+1,transno+1,n,k,prices,dp),find(i+1,transno,n,k,prices,dp));
    }
    else
    {
        profit=max(prices[i]+find(i+1,transno+1,n,k,prices,dp),find(i+1,transno,n,k,prices,dp));
    }
    return dp[i][transno]=profit;
}
*/


int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    //Method 1
    //vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    //return find(0,1,n,k,prices,dp);

    /*Mthod 1 -Dp-Tabulation TC=O(n*2*k) Sc=O(n*2*k)
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            for(int z=1;z<=k;z++)
            {
                if(j==1)
                {
                    dp[i][j][z]=max(-prices[i]+dp[i+1][0][z],dp[i+1][1][z]);
                }
                else
                {
                    dp[i][j][z]=max(prices[i]+dp[i+1][1][z-1],dp[i+1][0][z]);
                }
            }
        }
    }
    return dp[0][1][k];
    */

    /*Method 1-Dp-Space optimization TC=O(n*2*k) Sc=O(2*k)
    vector<vector<int>> curr(2,vector<int>(k+1,0));
    vector<vector<int>> next(2,vector<int>(k+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            for(int z=1;z<=k;z++)
            {
                if(j==1)
                {
                    curr[j][z]=max(-prices[i]+next[0][z],next[1][z]);
                }
                else
                {
                    curr[j][z]=max(prices[i]+next[1][z-1],next[0][z]);
                }
            }
        }
        next=curr;
    }
    return next[1][k];
    */


    //Method 2
    //vector<vector<int>> dp(n,vector<int>(2*k,-1));
    //return find(0,0,n,k*2,prices,dp);

    /*Method 2-Dp Tabulation TC=O(n*2*k) Sc=O(n*2*k)
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2*k-1;j>=0;j--)
        {
            if(j%2==0)
            {
                dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
            else
            {
                dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
    */

    //Method 2-Dp Space optimization TC=O(n*2*k) Sc=O(2*k)
    vector<int> curr(2*k+1,0);
    vector<int> next(2*k+1,0);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2*k-1;j>=0;j--)
        {
            if(j%2==0)
            {
                curr[j]=max(-prices[i]+next[j+1],next[j]);
            }
            else
            {
                curr[j]=max(prices[i]+next[j+1],next[j]);
            }
        }
        next=curr;
    }
    return next[0];
}





