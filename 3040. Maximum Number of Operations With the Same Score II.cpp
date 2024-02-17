/*problem statement:
Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:

Choose the first two elements of nums and delete them.
Choose the last two elements of nums and delete them.
Choose the first and the last elements of nums and delete them.
The score of the operation is the sum of the deleted elements.
Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.
Return the maximum number of operations possible that satisfy the condition mentioned above.

Input: nums = [3,2,1,2,3,4]
Output: 3
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
- Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
- Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
We are unable to perform any more operations as nums is empty.
*/
class Solution {
public:
    int dp[2001][2001];
    int find(int i,int j,vector<int>& nums,int s)
    {
        if(i==j)
            return 0;
        if(i+1==j)
        {
            if(nums[i]+nums[j]==s)
                return 1;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(nums[i]+nums[i+1]==s)
        {
            ans=max(ans,1+find(i+2,j,nums,s));
        }
        if(nums[j]+nums[j-1]==s)
        {
            
            ans=max(ans,1+find(i,j-2,nums,s));
        }
        if(nums[i]+nums[j]==s)
        {
            ans=max(ans,1+find(i+1,j-1,nums,s));
        }
        return dp[i][j]=ans;
    }
    int maxOperations(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int res=find(0,nums.size()-1,nums,nums[0]+nums[1]);
        
        memset(dp,-1,sizeof(dp));
        res=max(res,find(0,nums.size()-1,nums,nums[0]+nums[nums.size()-1]));
        
        memset(dp,-1,sizeof(dp));
        res=max(res,find(0,nums.size()-1,nums,nums[nums.size()-2]+nums[nums.size()-1]));
        return res;
    }
};
