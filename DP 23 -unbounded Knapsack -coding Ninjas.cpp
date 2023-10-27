#include<bits/stdc++.h>
/*memoization TC=O(i*w) SC=O(i*w)+O(w) stack space in worst case assume w=10 and weight[i]=1 so there will be 10 times i will be store in stack
int find(int i,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(w>=weight[0])
        {
            return profit[0]*(w/weight[0]);
        }
        else
            return 0;
        
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int not_take=find(i-1,w,profit,weight,dp);
    int take=INT_MIN;
    if(w>=weight[i])
        take=profit[i]+find(i,w-weight[i],profit,weight,dp);
    return dp[i][w]=max(take,not_take);
}
*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    //vector<vector<int>> dp(n,vector<int>(w+1,-1));
    //return find(n-1,w,profit,weight,dp);

    /*tabulation TC=O(n*w) sc=O(n*w)
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int j=0;j<=w;j++)
    {
        if(j>=weight[0])
            dp[0][j]=profit[0]*(j/weight[0]);
        else
            dp[0][j]=0;
    }
    for(int i=1;i<n;i++){
        for (int j = 0; j <= w; j++) {
            int not_take = dp[i - 1][j];
            int take = INT_MIN;
            if (j >= weight[i])
              take = profit[i] +dp[i][j - weight[i]];
            dp[i][j] = max(take, not_take);
        }
    }
    return dp[n-1][w];
    */

    /*space optimization TC=O(n*w) sc=O(w)+O(w) -2 vectors
    vector<int> dp(w+1,0);
    vector<int> dummy(w+1,0);
    for(int j=0;j<=w;j++)
    {
        if(j>=weight[0])
            dummy[j]=profit[0]*(j/weight[0]);
        else
            dummy[j]=0;
    }
    for(int i=1;i<n;i++){
        for (int j = 0; j <= w; j++) {
            int not_take = dummy[j];
            int take = INT_MIN;
            if (j >= weight[i])
              take = profit[i] +dp[j - weight[i]];
            dp[j] = max(take, not_take);
        }
        dummy=dp;
    }
    return dummy[w];
    */

    //space optimization TC=O(n*w) sc=O(w) -1 vectors
    //bc element in current row depends only on one element in previous row in same index and all the elements in current row
    vector<int> dummy(w+1,0);
    for(int j=0;j<=w;j++)
    {
        if(j>=weight[0])
            dummy[j]=profit[0]*(j/weight[0]);
        else
            dummy[j]=0;
    }
    for(int i=1;i<n;i++){
        for (int j = 0; j <= w; j++) {
            int not_take = dummy[j];
            int take = INT_MIN;
            if (j >= weight[i])
              take = profit[i] +dummy[j - weight[i]];
            dummy[j] = max(take, not_take);
        }
    }
    return dummy[w];

}
