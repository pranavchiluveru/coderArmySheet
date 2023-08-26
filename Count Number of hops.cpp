//Function to count the number of ways in which frog can reach the top.
    long long find(vector<long long> &dp,int n)
    {
        if(dp[n]!=-1)
            return dp[n];
        if(n==1)
            return dp[1]=1;
        if(n==2)
            return dp[2]=2;
        if(n==3)
            return dp[3]=4;
        return dp[n]=(find(dp,n-1)+find(dp,n-2)+find(dp,n-3))%1000000007;
    }
    
    long long countWays(int n)
    {
        
        // your code here
        
        vector<long long> dp(n+1,-1);
        return find(dp,n);
        
        
    }
