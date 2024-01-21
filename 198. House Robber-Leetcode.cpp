class Solution {
public:
    /*DP-Memoization TC=O(n) SC=O(n)
    int find(int i,vector<int>& nums,vector<int> dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+find(i+2,nums,dp);
        int not_take=find(i+1,nums,dp);
        return dp[i]=max(take,not_take);
    }
    */
    int rob(vector<int>& nums) {
        //vector<int> dp(nums.size(),-1);
        //return find(0,nums,dp);
        /*Dp -Tabulation TC=O(n) SC=O(n)
        vector<int> dp(nums.size()+2,0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            int take=nums[i]+dp[i+2];
            int not_take=dp[i+1];
            dp[i]=max(take,not_take);
        }
        return dp[0];
        */
        //TC=O(n) SC=O(1)
        int num2=0,num1=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            int take=nums[i]+num2;
            int not_take=num1;
            int num=max(take,not_take);
            num2=num1;
            num1=num;
        }
        return num1;
    }
};
