#include <bits/stdc++.h> 
/* Top down -TC=O(n) C=O(n)+O(n)
int find(int i,vector<int> &nums,vector<int> &dp)
{
    if(i<0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    return dp[i]=max(nums[i]+find(i-2,nums,dp),find(i-1,nums,dp));
    
}
*/

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    //vector<int> dp(n,-1);
    //return find(n-1,nums,dp);
    /*Bottom Up TC=O(n) Sc=O(n)
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i = 2; i <n; i++) {
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
    */
    //space optimization TC=O(n), Sc=O(1)
    int first=nums[0];
    int second=max(nums[0],nums[1]);
    for (int i = 2; i <n; i++) {
        int third=max(nums[i]+first,second);
        first=second;
        second=third;
    }
    return second;

}
