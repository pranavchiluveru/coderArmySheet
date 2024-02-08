class Solution {
public:
    /*Recursion TC=O(2^n) 
    int find(int n)
    {
        if(n==0)
            return 0;
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+find(n-i*i));
        }
        return ans;
    }
    */
    /*DP -Memoization TC=O(n*srqt(n)) SC=O(n)
    int find(int n,vector<int> dp)
    {
        if(n==0)
            return 0;
        
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+find(n-i*i,dp));
        }
        return dp[n]=ans;
    }
    */
    int numSquares(int n) {
        /*
        vector<int> dp(n+1,-1);
        return find(n,dp);
        */
        //DP-Tabulation TC=O(n*srqt(n)) SC=O(n)
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {   
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
        
        
    }
};
