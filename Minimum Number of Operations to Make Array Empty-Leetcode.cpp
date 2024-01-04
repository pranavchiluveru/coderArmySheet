#include<bits/stdc++.h>
class Solution {
public:
    /*
    int solve(int i,vector<int>& nums,int n,vector<int> &dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int x=1e9,y=1e9;
        if(i+1<n&&nums[i]==nums[i+1])
            x=1+solve(i+2,nums,n,dp);
        if(i+2<n&&nums[i]==nums[i+2])
            y=1+solve(i+3,nums,n,dp);
        return dp[i]=min(x,y);
    }
    */
    int minOperations(vector<int>& nums) {
        //method 1:Tc=O(n) SC=O(n)
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int op=0;
        for(auto it:m)
        {
            if(it.second==1)
                return -1;
            op+=it.second/3;
            if(it.second%3)op++;
        }
        return op;
        /*Using DP Tc=O(nlogn)+O(n) SC=O(n)
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        int res=solve(0,nums,n,dp);
        if(res>=1e9)
            return -1;
        return res;
        */
    }
};
