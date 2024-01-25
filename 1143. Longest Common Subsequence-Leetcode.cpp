class Solution {
public:
    /*DP -Memoization TC=O(n*m) SC=O(n*m)
    int find(int i,int j,int n,int m,string text1, string text2,vector<vector<int>> &dp)
    {
        if(i==n||j==m)
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j])
        {
            return dp[i][j]=1+find(i+1,j+1,n,m,text1,text2,dp);
        }
        else
        {
            return dp[i][j]=max(find(i+1,j,n,m,text1,text2,dp),find(i,j+1,n,m,text1,text2,dp));
        }
    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        //vector<vector<int>> dp(n,vector<int>(m,-1));
        //return find(0,0,n,m,text1,text2,dp);
        /*Dp -Tabulation TC=O(n*m) SC=O(n*m)
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
        */

        /*DP-Space optimization TC=O(n*m) SC=O(m)
        vector<int> next(m+1,0);
	    vector<int> curr(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                    curr[j]=1+next[j+1];
                else
                    curr[j]=max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return curr[0];

    }
};
