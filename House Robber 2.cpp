//Given array of size n. index 0 is neighbour of index n-1 .circular houses .so if we take index 0 we cant take index n-1 and vice versa.
// so first we take houses from index 0 to n-2 .Then we take houses form index 1 to n-1. return max of those two

class Solution {
public:
    /*Naive: recursion
    int find(int i,int n,vector<int>& nums)
    {
        if(i>=n)
            return 0;
        return max(nums[i]+find(i+2,n,nums),find(i+1,n,nums));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int includeFirstExcludeLast=find(0,n-1,nums);
        int excluseFirstIncludeLast=find(1,n,nums);
        return max(includeFirstExcludeLast,excluseFirstIncludeLast);
    }
    */

    /*DP : Top Down
    int find(int i,int n,vector<int>& nums,vector<int>& dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max(nums[i]+find(i+2,n,nums,dp),find(i+1,n,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        if(n==1)
            return nums[0];
        int includeFirstExcludeLast=find(0,n-1,nums,dp1);
        int excluseFirstIncludeLast=find(1,n,nums,dp2);
        return max(includeFirstExcludeLast,excluseFirstIncludeLast);
    }
    */

    /*DP: Bottom UP
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n+2);
        dp[n]=0;
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        int includeFirstExcludeLast=dp[0];

        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>=1;i--)
        {
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        int excluseFirstIncludeLast=dp[1];
        return max(includeFirstExcludeLast,excluseFirstIncludeLast);

    }

    */
    //space optimization
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int first=0;
        int second=0;
        int third;
        for(int i=n-2;i>=0;i--)
        {
            third=max(nums[i]+second,first);
            second=first;
            first=third;
        }
        int includeFirstExcludeLast=third;

        first=second=0;
        for(int i=n-1;i>=1;i--)
        {
            third=max(nums[i]+second,first);
            second=first;
            first=third;
        }
        int excluseFirstIncludeLast=third;
        return max(includeFirstExcludeLast,excluseFirstIncludeLast);

    }
};
