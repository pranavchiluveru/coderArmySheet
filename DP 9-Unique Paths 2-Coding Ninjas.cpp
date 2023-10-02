#include<bits/stdc++.h>
int mod=1e9+7;
/*DP-Top Down TC=O(n*m) SC=O(n*m)+O(n+m)
int find(int i, int j, vector< vector< int> > &mat,vector<vector<int>> &dp)
{
    if(i==0&& j==0)return 1;
    if(i<0||j<0)return 0;
    if(i>=0&&j>=0&&mat[i][j]==-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=find(i-1,j,mat,dp);
    int left=find(i,j-1,mat,dp);
    return dp[i][j]=(up+left)%mod;
}
*/
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    //vector<vector<int>> dp(n,vector<int>(m,-1));
    //return find(n-1,m-1,mat,dp);

    /*Bottom-UP TC=O(n*m) SC=O(n*m)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0&&j==0)dp[0][0]=1;
            else if (mat[i][j]==-1)dp[i][j]=0;
            else
            {
                int up=0,left=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
    */
    //space optimization TC=O(n*m) SC=O(m)
    vector<int> dummy(m,0);
    vector<int> dp(m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0&&j==0)dp[j]=1;
            else if (mat[i][j]==-1)dp[j]=0;
            else
            {
                int up=0,left=0;
                if(i>0)
                    up=dummy[j];
                if(j>0)
                    left=dp[j-1];
                dp[j]=(up+left)%mod;
            }
        }
        dummy=dp;
    }
    return dummy[m-1];

    
}
