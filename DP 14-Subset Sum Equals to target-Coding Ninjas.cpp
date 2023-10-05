#include <bits/stdc++.h>
/*Top Down -TC=O(n*k) SC=O(n*k)+O(n)
bool find(int i,int tar,vector<int> &arr,vector<vector<int>> &dp)
{
    if(tar==0)return true;
    if(i==0) return arr[0]==tar;
    if(dp[i][tar]!=-1)return dp[i][tar];
    bool not_take=find(i-1,tar,arr,dp);
    bool take=false;
    if(tar>=arr[i])
        take=find(i-1,tar-arr[i],a,dp);
    return dp[i][tar]=take|not_take;

}
*/
bool subsetSumToK(int n, int k, vector<int> &arr) {
  // Write your code here.
  /*Top down-
  vector<vector<int>> dp(n,vector<int>(k+1,-1));
  return find(n-1,k,arr,dp);
  */
  /* Bottom Up -TC=O(n*k) SC=O(n*k)
  vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
  for (int i = 0; i < n; i++)
        dp[i][0] = true;
  dp[0][arr[0]] = true;
  for (int i = 1; i < n; i++) {
    for (int tar = 1; tar <= k; tar++) {
      bool not_take = dp[i-1][tar];
      bool take = false;
      if (tar >= arr[i])
        take = dp[i-1][tar-arr[i]];
      dp[i][tar] = take | not_take;
    }
  }
  return dp[n-1][k];
  */
  //Space optimization -TC=O(n*k) SC=O(k)
  vector<bool> dummy(k+1,0);
  vector<bool> dp(k+1);
  dummy[0]=true;
  dp[0]=true;
  dummy[arr[0]]=true;
  for (int i = 1; i < n; i++) {
    for (int tar = 1; tar <= k; tar++) {
      bool not_take = dummy[tar];
      bool take = false;
      if (tar >= arr[i])
        take = dummy[tar-arr[i]];
      dp[tar] = take | not_take;
    }
    dummy=dp;
  }
  return dummy[k];

}
