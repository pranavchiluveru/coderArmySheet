#include <bits/stdc++.h>
/*Top DOwn Tc=O(n*k) SC=O(n*k)+O(n)
int find(int i, int k, vector<int> &arr,vector<vector<int>> &dp) {
  if (k == 0)
    return 1;
  if (i == 0) return arr[0]==k;
  if(dp[i][k]!=-1)return dp[i][k];
  int not_take = find(i - 1, k, arr,dp);
  int take = 0;
  if (arr[i] <= k)
    take = find(i - 1, k - arr[i], arr,dp);
  return take + not_take;
}
*/
int findWays(vector<int> &num, int k) {
  // Write your code here.
  int n = num.size();
  //vector<vector<int>> dp(n,vector<int>(k+1,-1));
  //return find(n - 1, k, arr,dp);
  	
	/*Bottom Up -TC=O(n*k) SC=O(n*k)

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first row based on the first element of the array
    if (num[0] <= k) {
        dp[0][num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dp[ind - 1][target - num[ind]];
            }

            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
	*/

	//Space Optimization TC=O(n*k) SC=O(n)
	vector<int> dummy(k+1,0);
	vector<int> dp(k+1);
	dummy[0]=dp[0]=1;
	dummy[num[0]]=1;
	for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = dummy[target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dummy[target - num[ind]];
            }

            // Update the DP table
            dp[target] = notTaken + taken;
        }
		dummy=dp;
    }

    // The final result is in the last cell of the DP table
    return dummy[k];
	

  
}
