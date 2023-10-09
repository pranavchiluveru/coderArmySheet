#include <bits/stdc++.h>
int mod=1e9+7;
/*Top DOwn Tc=O(n*k) SC=O(n*k)+O(n)
int find(int i, int k, vector<int> &arr,vector<vector<int>> &dp) {
  if(i == 0)
  {
    if(k==0&&arr[0]==0)return 2;
    if(k==0)return 1;
    if(arr[0]==k)return 1;
    return 0;
  }
  if(dp[i][k]!=-1)return dp[i][k];
  int not_take = find(i - 1, k, arr,dp);
  int take = 0;
  if (arr[i] <= k)
    take = find(i - 1, k - arr[i], arr,dp);
  return dp[i][k]=(take + not_take)%mod;
}
*/
int findWays(vector<int> &num, int k) {
  // Write your code here.
  int n = num.size();
  //vector<vector<int>> dp(n,vector<int>(k+1,-1));
  //return find(n - 1, k, num,dp);
  	
	/*Bottom Up -TC=O(n*k) SC=O(n*k)

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if(num[0]==0)dp[0][0]=2;//take or not take k will be 0 only so 2 options
    else dp[0][0]=1;
    if(num[0]!=0)dp[0][num[0]]=1;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dp[ind - 1][target - num[ind]];
            }

            // Update the DP table
            dp[ind][target] = (notTaken + taken)%mod;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
  */

	//Space Optimization TC=O(n*k) SC=O(n)
	vector<int> dummy(k+1,0);
	vector<int> dp(k+1);
  if(num[0]==0)dummy[0]=2;//take or not take k will be 0 only so 2 options
  else dummy[0]=1;
  if(num[0]!=0)dummy[num[0]]=1;

	for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= k; target++) {
            // Exclude the current element
            int notTaken = dummy[target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dummy[target - num[ind]];
            }

            // Update the DP table
            dp[target] = (notTaken + taken)%mod;
        }
		    dummy=dp;
    }

    // The final result is in the last cell of the DP table
    return dummy[k];
	

  
}
