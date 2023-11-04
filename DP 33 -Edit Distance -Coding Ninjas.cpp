#include<bits/stdc++.h>
/*Recursion TC=exponential=O(3^(n+m)) ,sc=O(n+m)
find(i,j) implies min no. of steps req. to make str1[0..i] to str2[0..j]
int find(int i,int j,string &str1, string &str2)
{
    if(i<0)return j+1;    ...if str1= "" str2="abc" i.e i=-1,j=2 then to convert str1 to str2 we need to do 3 insertions i.e j+1 
    if(j<0)return i+1;      ...if str1= "jkl" str2="" i.e i=2,j=-1 then to convert str1 to str2 we need to do 3 deletions i.e i+1 
    if(str1[i]==str2[j])
        return find(i-1,j-1,str1,str2);
    else
        return 1+min(find(i-1,j,str1,str2),min(find(i-1,j-1,str1,str2),find(i,j-1,str1,str2))); ...min(delete,min(replace,insert))
}
*/
/*Dp-Memoization TC=O(n*m) SC=O(n*m)+O(n+m)
int find(int i,int j,string &str1, string &str2,vector<vector<int>> &dp)
{
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i]==str2[j])
        return dp[i][j]=find(i-1,j-1,str1,str2,dp);
    else
        return dp[i][j]=1+min(find(i-1,j,str1,str2,dp),min(find(i-1,j-1,str1,str2,dp),find(i,j-1,str1,str2,dp)));
}
*/
int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.size();
    int m=str2.size();
    //vector<vector<int>> dp(n,vector<int>(m,-1));
    //return find(n-1,m-1,str1,str2,dp);

    /*DP-Tabulation TC=O(n*m) SC=O(n*m) convert index from 0  to 1 so that we can cover base cases i<0 j<0
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int j=1;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else   
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    return dp[n][m];
    */

    //space optimization TC=O(n*m) SC=O(m)
    vector<int> curr(m+1,0);
    vector<int> prev(m+1,0);
    for(int j=1;j<=m;j++)
        prev[j]=j;
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                curr[j]=prev[j-1];
            else   
                curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
        }
        prev=curr;
    }
    return curr[m];
    

}
