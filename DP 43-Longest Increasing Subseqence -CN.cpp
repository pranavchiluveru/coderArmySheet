class Solution {
public:
    /*Recursion TC=O(2^n) SC=O(n)
    int find(int i,int prev,vector<int>& nums1,int n)
    {
        if(i==n)return 0;
        int x=0,y=0;
        if(prev==-1||nums1[prev]<nums1[i])
        {
            x=1+find(i+1,i,nums1,n);
        }
        y=find(i+1,prev,nums1,n);
        return max(x,y);
    }
    */
    /*DP-Top Down -Memoization TC=O(n2) SC=O(n2)
    int find(int i,int prev,vector<int>& nums1,int n,vector<vector<int>> &dp)
    {
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int x=0,y=0;
        if(prev==-1||nums1[prev]<nums1[i])
        {
            x=1+find(i+1,i,nums1,n,dp);
        }
        y=find(i+1,prev,nums1,n,dp);
      
        return dp[i][prev+1]=max(x,y);
    }
    */
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //return find(0,-1,nums,n,dp);

        /*DP-Bottom Up -Tabulation TC=O(n2) SC=O(n2)
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                if(prev==-1||nums[prev]<nums[i])
                {
                    dp[i][prev+1]=max(1+dp[i+1][i+1],dp[i+1][prev+1]);
                }
                else
                    dp[i][prev+1]=dp[i+1][prev+1];
            }
        }
        return dp[0][-1+1];
        */
        /*Space optimization TC=O(n2) SC=O(n)
        vector<int> next(n+1,0);
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                if(prev==-1||nums[prev]<nums[i])
                    dp[prev+1]=max(1+next[i+1],next[prev+1]);
                else
                    dp[prev+1]=next[prev+1];
            }
            next=dp;
        }
        return dp[0];
        */

        //optimal way TC=O(nlogn) SC=O(n)
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(temp.back()<nums[i])
                temp.push_back(nums[i]);
            else
            {
                int index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[index]=nums[i];
            }
        }
        return temp.size();
    }
};
