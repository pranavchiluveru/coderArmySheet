#include<bits/stdc++.h>
/*Recursion TC=exponential sc=O(n+m)
bool find(int i,int j,string &pattern, string &text)
{
   if(i<0&&j<0)      ....if both strings exhaust return true
      return true;
   if(i<0&&j>=0)return false;    ....if pattern exhausted and text left then there is no pattern to match text so return false
   if(j<0 &&i>=0)    ...if pattern left and text exhausted it will be true only if pattern has '*'s ;if pattern has any character it doesn't have any text to match so return false 
   {
      for(int k=0;k<=i;k++)
      {
         if(pattern[k]!='*')
            return false;
      }
      return true;
   }
   if(pattern[i]==text[j]||pattern[i]=='?')     ..if match do i-1,j-1 (or) if pattern has '?' it will match one character of text so do i-1,j-1
      return find(i-1,j-1,pattern,text);
   if(pattern[i]=='*')           ...if pattern encountered '*' it can match 0 or more characters of text
      return find(i-1,j,pattern,text)|find(i,j-1,pattern,text);
   return false;        ....if not match return false;
}
*/
/*DP_Memoization TC=O(n*m) SC=O(n*m)+O(n+m)
bool find(int i,int j,string &pattern, string &text,vector<vector<int>> &dp)
{
   if(i<0&&j<0)
      return true;
   if(i<0&&j>=0)return false;
   if(j<0 &&i>=0)
   {
      for(int k=0;k<=i;k++)
      {
         if(pattern[k]!='*')
            return false;
      }
      return true;
   }
   if(dp[i][j]!=-1)return dp[i][j];
   if(pattern[i]==text[j]||pattern[i]=='?')
      return dp[i][j]=find(i-1,j-1,pattern,text,dp);
   else if(pattern[i]=='*')
      return dp[i][j]=find(i-1,j,pattern,text,dp)|find(i,j-1,pattern,text,dp);
   else
      return dp[i][j]=false;
}
*/
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n=pattern.size();
   int m=text.size();
   //return find(n-1,m-1,pattern,text);

   //vector<vector<int>> dp(n,vector<int>(m,-1));
   //return find(n-1,m-1,pattern,text,dp);

   /*Tabulation TC=O(n*m) SC=O(n*m)
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
   dp[0][0]=1;
   for(int j=1;j<=m;j++)
      dp[0][j]=0;
   bool flag=true;
   for(int i=1;i<=n;i++)
   {
      for(int k=1;k<=i;k++)
      {
         if(pattern[k-1]!='*')
         {
            flag=false;
            break;
         }
      }
      if(flag==false)
         dp[i][0]=0;
      else
         dp[i][0]=1;
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         if(pattern[i-1]==text[j-1]||pattern[i-1]=='?')
            dp[i][j]=dp[i-1][j-1];
         else if(pattern[i-1]=='*')
            dp[i][j]=dp[i-1][j]|dp[i][j-1];
         else
            dp[i][j]=0;
      }
   }
   return dp[n][m];
   */

   //space optimization TC=O(n*m) SC=O(m)
   vector<int> prev(m+1,0);
   vector<int> curr(m+1,0);
   prev[0]=1;
   for(int j=1;j<=m;j++)
      prev[j]=0;
   
   for(int i=1;i<=n;i++)
   {
      bool flag=true;
      for(int k=1;k<=i;k++)
      {
         if(pattern[k-1]!='*')
         {
            flag=false;
            break;
         }
      }
      if(flag==false)
         curr[0]=0;
      else
         curr[0]=1;
      for(int j=1;j<=m;j++)
      {
         if(pattern[i-1]==text[j-1]||pattern[i-1]=='?')
            curr[j]=prev[j-1];
         else if(pattern[i-1]=='*')
            curr[j]=prev[j]|curr[j-1];
         else
            curr[j]=0;
      }
      prev=curr;
   }
   return prev[m];
   

}
