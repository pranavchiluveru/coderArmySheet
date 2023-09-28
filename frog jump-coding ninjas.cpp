#include <bits/stdc++.h> 
/* DP -TopDown SC=O(n)+O(n)  TC=O(n)
int find(int i, vector<int> &heights,vector<int> &dp)
{
    if(i==0) return 0;
    if(i==1) return abs(heights[i]-heights[i-1]);
    if(dp[i]!=-1)
        return dp[i];
    int l=find(i-1,heights,dp)+abs(heights[i]-heights[i-1]);
    int r=find(i-2,heights,dp)+abs(heights[i]-heights[i-2]); 
    return dp[i]=min(l,r);   
}
*/
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    //return find(n-1,heights,dp);

    //Bottom Up SC=O(n) TC=O(n)
    /*
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    for(int i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+abs(heights[i]-heights[i-1]),dp[i-2]+abs(heights[i]-heights[i-2]));
    }
    return dp[n-1];
    */

    //Bottom Up with space optimization SC=O(1),TC=O(n)
    int first=0;
    int second=abs(heights[1]-heights[0]);
    for (int i = 2; i < n; i++) {
      int third = min(second + abs(heights[i] - heights[i - 1]),first + abs(heights[i] - heights[i - 2]));
      first = second;
      second = third;
    }
    return second;

}
