class Solution {
public:
    /*Naive Approach: Recursion 
    int find(vector<int>& arr, int ind,int k,int n)
    {
        int currmax=0,maxsum=0,currsum=0;
        for(int i=ind;i<min(ind+k,n);i++)
        {
            currmax=max(currmax,arr[i]);
            currsum=currmax*(i-ind+1)+find(arr,i+1,k,n);
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
    */
    /*Dp-Memoization TC=O(n*k) SC=O(n)
    int find(vector<int>& arr, int ind,int k,int n,vector<int> &dp)
    {
        if(ind==n)return 0;
        int currmax=0,maxsum=0,currsum=0;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<min(ind+k,n);i++)
        {
            currmax=max(currmax,arr[i]);
            currsum=currmax*(i-ind+1)+find(arr,i+1,k,n,dp);
            maxsum=max(maxsum,currsum);
        }
        return dp[ind]=maxsum;
    }
    */
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        //vector<int> dp(n,-1);
        //return find(arr,0,k,n,dp);
        //Dp-Tabulation TC=O(n*k) SC=O(n)
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            int currmax=0,maxsum=0,currsum=0;
            for(int i=ind;i<min(ind+k,n);i++)
            {
                currmax=max(currmax,arr[i]);
                currsum=currmax*(i-ind+1)+dp[i+1];
                maxsum=max(maxsum,currsum);
            }
            dp[ind]=maxsum;
        }
        return dp[0];
    }
};
