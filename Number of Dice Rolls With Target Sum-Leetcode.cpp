class Solution {
public:
    int MOD = 1e9 + 7;
    /*Memoization TC=O(n*target*k)  SC=O(n*target)
    int find(int n,int k,int target,vector<vector<int>> &dp)
    {
        if(n==0&&target==0)
            return 1;
        if(n==0||target<0)return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        int ways=0;  
        for(int i=1;i<=k;i++)
        {
            ways=(ways+find(n-1,k,target-i,dp))%MOD;
        }
        return dp[n][target]=ways;
    }
    */
    int numRollsToTarget(int n, int k, int target) {
       //vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
       //return find(n,k,target,dp);

        /*tabulation TC=O(n*target*k) SC=O(n*target)
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int z=1;z<=k;z++)
                {
                    if(j>=z)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-z])%MOD;
                }
            }
        }
        return dp[n][target];
        */
        //space optimization TC=O(n*target*k) SC=O(target)
        vector<int> prev(target+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++)
        {
            vector<int> dp(target+1,0);
            for(int j=1;j<=target;j++)
            {
                for(int z=1;z<=k;z++)
                {
                    if(j>=z)
                        dp[j]=(dp[j]+prev[j-z])%MOD;
                }
            }
            prev=dp;
        }
        return prev[target];
    }
};
