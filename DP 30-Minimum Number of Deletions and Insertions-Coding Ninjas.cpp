#include<bits/stdc++.h>
//Tabulation Dp-TC=O(n*m)SC=O(n*m)
int LCS(int n,int m,string &s1, string &s2,vector<vector<int>> &dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }
    return dp[n][m];
}
int canYouMake(string &s1, string &s2){
    // Write your code here.
    //logic find LongestCommonsubsequence(s1,s2)->we get "ac" so we need to do 4-2 deletions(b,d) in s1 and add (3-2) additions(n) (which is equivalent to deleting(3-2) from s2) to get s2 
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int lcs=LCS(n,m,s1,s2,dp);
    return n-lcs+m-lcs;
}
