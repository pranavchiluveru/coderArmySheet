#include<bits/stdc++.h>
class Solution {
public:
    //watch ayushi video youtube
    /*Naive Approach
    bool check(vector<int> arr,int k)
    {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    count++;
                }
            }
        }
        return count==k;
    }
    */
    /*Dp-memoization
    int mod=1e9+7;
    int find(int n,int k,vector<vector<int>> &dp)
    {
        if(n==0)return 0;
        if(k==0)return 1;
        if(dp[n][k]!=-1)return dp[n][k];
        int res=0;
        for(int i=0;i<=min(k,n-1);i++)
        {
            res=(res+kInversePairs(n-1,k-i))%mod;
        }
        return dp[n][k]=res;
    }
    */
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        /*Naive Approach
        int res=0;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(i+1);
        }
        do{
            if(check(arr,k))
                res++;
        }while(next_permutation(arr.begin(),arr.end()));
        return res;
        */
        /*DP-memoizaion 
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return find(n,k,dp);
        */
        //DP -Tabulation TC=O(n*k*k) SC=O(n*k)
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++)//first ele to last
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else
                {
                    int res=0;
                    for(int p=0;p<=min(j,i-1);p++)
                        res=(res+dp[i-1][j-p])%mod;
                    dp[i][j]=res;
                }
            }
        }
        return dp[n][k];
        
    }
};
