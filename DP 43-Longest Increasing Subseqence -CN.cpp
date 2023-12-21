#include<bits/stdc++.h>
/*Recursion TC=O(2^n) Sc=O(n)
int find(int i,int prev,int arr[],int n)
{
    if(i==n)return 0;
    if(arr[i]>arr[prev]||prev==-1)
    {
        return max(1+find(i+1,i,arr,n),find(i+1,prev,arr,n));
    }
    return find(i+1,prev,arr,n,dp);
}
*/
/*Dp-Memoization TC=O(n*n) Sc=O(n*n)
int find(int i,int prev,int arr[],int n,vector<vector<int>> &dp)
{
    if(i==n)return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    if(prev==-1||arr[i]>arr[prev])
    {
        return dp[i][prev+1]=max(1+find(i+1,i,arr,n,dp),find(i+1,prev,arr,n,dp));//since we cant have prev as -1 we add +1
    }
    return dp[i][prev+1]=find(i+1,prev,arr,n,dp);
}
*/
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here.
    //find(0,-1) indicate length of LIS starting at index 0 with previous index as -1
    //find(3,1) indicate what is the length of LIS starting at index 3 with previous index as 1
    //return find(0,-1,arr,n);

    //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //return find(0,-1,arr,n,dp);

    /*DP -Tabulation TC=O(n^2) sc=O(n^2)
    for(int i=n-1;i>=0;i--)
    {
        for(int prev=i-1;prev>=-1;prev--)
        {
            if(prev==-1||arr[i]>arr[prev])
            {
                dp[i][prev+1]=max(1+dp[i+1][i+1],dp[i+1][prev+1]);//since we cant have prev as -1 we add +1
            }
            else
                dp[i][prev+1]=dp[i+1][prev+1];
        }
    }
    return dp[0][-1+1];
    */

    //Using Binary search lower_bound which finds index of ele which is equal or greater than req ele
    //tc=O(n*log(n)) sc=O(n)
    vector<int> temp;//note this doesnot contain LIS its just for length
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
            temp.push_back(arr[i]);
        else{
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();//takes log(n) time binary search
            temp[index]=arr[i];
        }
    }
    return temp.size();
}
