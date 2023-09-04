class Solution {
public:
    int find(int s1,int s2,int m1,int m2,vector<vector<int>> &dp)
    {
        if(dp[s1][s2]!=-1)
            return dp[s1][s2];
        if(s1>=m1 || s2>=m2)
            return 0;
        if(s1==m1-1&&s2==m2-1)
        {
            return 1;
        }
        return dp[s1][s2]=find(s1+1,s2,m1,m2,dp)+find(s1,s2+1,m1,m2,dp);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return find(0,0,m,n,dp);
    }
};
