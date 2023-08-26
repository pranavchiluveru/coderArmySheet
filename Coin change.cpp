    long long int find(int coins[], int index,int N, int sum, vector<vector<long long int>> &dp)
    {
       
        if(sum==0)
        {
            return 1;
        }
        if(index==N||sum<0)
        {
            return 0;
        }
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        return dp[index][sum]=find(coins,index,N,sum-coins[index],dp)+find(coins,index+1,N,sum,dp);
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        int index=0;
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
        return find(coins,index,N,sum,dp);
    
        
    }
