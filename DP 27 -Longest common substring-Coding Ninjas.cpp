#include<bits/stdc++.h>

/*
Recursion -Time complexity: O(2 ^ (N + M)) Space complexity: O(max(N, M))
int lcsHelper(int n, int m,string &str1, string &str2, int count){
    if (m < 0 || n <0){
        return count;
    }
    if (str1[n] == str2[m]){
        count = lcsHelper(str1, str2, n - 1, m - 1, count + 1);
    }
    return max({count, lcsHelper(str1, str2, n - 1, m, 0), lcsHelper(str1, str2, n, m - 1, 0)});
     
}
*/

int lcs(string &str1, string &str2){
    // Write your code here.
    int n=str1.size();
    int m=str2.size();
    //recursion-return lcsHelper(str1, str2, n-1,m-1, 0);

    /*DP -Tabulation TC=O(n*m),SC=O(n*m)
    int res=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                res=max(res,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }

        }
    }
    return res;
    */

    //space optimization TC=O(n*m),SC=O(m)
    int res=0;
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                curr[j]=1+prev[j-1];
                res=max(res,curr[j]);
            }
            else
            {
                curr[j]=0;
            }

        }
        prev=curr;
    }
    return res;


}
