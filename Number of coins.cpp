int findmin(int coins[],int index, int M, int V,vector<vector<int>> &dp)
	{
	    if(V==0)
	    {
	        return 0;
	    }
	    if(index==M||V<0)
	    {
	        return 1e8;
	    }
	    if(dp[index][V]!=-1)
	        return dp[index][V];
	    int include=findmin(coins,index,M,V-coins[index],dp)+1;
	    int exclude=findmin(coins,index+1,M,V,dp);
	    return dp[index][V]=min(include,exclude);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int index=0;
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    int res=findmin(coins,index,M,V,dp);
	    if(res>=1e8)
	        return -1;
	    return res;
	} 
