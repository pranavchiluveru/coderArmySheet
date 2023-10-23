#include<bits/stdc++.h>
/*Recursion  TC>>2^n say as exponential  SC>>n O(value) in worst case
long find(int i,int value,int *denominations)//f(i,value)==till index i how many ways to form value
{
    if(value==0)
        return 1;
    if(value<0)
        return 0;
    if(i==0)return value%denominations[0]==0;//bc value is 4 denomination[0] is 1 then we can form 4 as 1+1+1+1
    long notconsider=find(i-1,value,denominations);
    long consider=0;
    if(denominations[i]<=value)
        consider=find(i,value-denominations[i],denominations);
    return consider+notconsider;
}
*/
/*Memoization TC=O(n*value) SC=O(n*value)+O(value): DP+stack space
long find(int i,int value,int *denominations,vector<vector<long>> &dp)//f(i,value)==till index i how many ways to form value
{
    if(value==0)
        return 1;
    if(value<0)
        return 0;
    if(i==0)return value%denominations[0]==0;//bc value is 4 denomination[0] is 1 then we can form 4 as 1+1+1+1
    if(dp[i][value]!=-1)return dp[i][value];
    long notconsider=find(i-1,value,denominations,dp);
    long consider=0;
    if(denominations[i]<=value)
        consider=find(i,value-denominations[i],denominations,dp);
    return dp[i][value]=consider+notconsider;
}
*/

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    //vector<vector<long>> dp(n,vector<long>(value+1,-1));
    //return find(n-1,value,denominations,dp);

    /*Tabulation TC=O(n*value) SC=O(n*value)
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(int j=0;j<=value;j++)
        dp[0][j]=j%denominations[0]==0;
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=value;j++)
        {
            long notconsider=dp[i-1][j];
            long consider=0;
            if(denominations[i]<=j)
                consider=dp[i][j-denominations[i]];
            dp[i][j]=consider+notconsider;
        }
    }
    return dp[n-1][value];
    */

    //Space Optimization TC=O(n*value) SC=O(value)
    vector<long> dp(value+1,0);
    vector<long> dummy(value+1,0);
    for(int j=0;j<=value;j++)
        dummy[j]=j%denominations[0]==0;
    dummy[0]=1;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=value;j++)
        {
            long notconsider=dummy[j];//going to i-1 so use dummy
            long consider=0;
            if(denominations[i]<=j)
                consider=dp[j-denominations[i]];//in same i so use dp
            dp[j]=consider+notconsider;
        }
        dummy=dp;
    }
    return dummy[value];
    


}
