#include <bits/stdc++.h> 
/*Dp-memoization TC=O(n*n) SC=O(n*n)+O(n+n)
int find(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i<0||j<0)
        return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])
        return 1+find(i-1,j-1,s1,s2,dp);
    return max(find(i-1,j,s1,s2,dp),find(i,j-1,s1,s2,dp));

}*/

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string s1=s;
    string s2=s;
    reverse(s2.begin(),s2.end());
    int n=s1.size();
    //now we check longest common subsequence which will be longestPalindromeSubsequence
    //vector<vector<int>> dp(n,vector<int>(n,-1));
    //return find(n-1,n-1,s1,s2,dp);
    //Tabulation -TC=O(n*n),SC=O(n*n)
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];

    //can do space optimization as well
}
