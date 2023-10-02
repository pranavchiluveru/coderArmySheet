#include <bits/stdc++.h>
/*top Down -TC=O(row*col) SC=O(row*col)+O(row+col)
int find(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
{

    if(i==0&&j==0)return grid[i][j];
    if(i<0||j<0)return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=find(i-1,j,grid,dp);
    int left=find(i,j-1,grid,dp);
    return dp[i][j]=grid[i][j]+min(up,left);
}
*/
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int row=grid.size();
    int col=grid[0].size();
    //vector<vector<int>> dp(row,vector<int>(col,-1));
    //return find(row-1,col-1,grid,dp);

    /*Bottom UP TC=O(row*col) SC=O(row*col)
    dp[0][0]=grid[0][0];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0&&j==0)continue;
            else
            {
                int up=INT_MAX,left=INT_MAX;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,left);
            }
        }
    }
    return dp[row-1][col-1];
    */

    //space optimation TC=O(row*col) SC=O(col)
    vector<int> dummy(col,0);
    vector<int> dp(col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0&&j==0)dp[0]=grid[i][j];
            else
            {
                int up=INT_MAX,left=INT_MAX;
                if(i>0)
                    up=dummy[j];
                if(j>0)
                    left=dp[j-1];
                dp[j]=grid[i][j]+min(up,left);
            }
        }
        dummy=dp;
    }
    return dummy[col-1];
}
