#include <bits/stdc++.h> 
/*Top  Down-TC=O(row*col) SC=dp array+recursion=O(row*col)+O(col)
int find(int i,int j,int row,int col,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    if(j<0||j>=col)return INT_MIN;
    if(i==row-1)return matrix[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=matrix[i][j]+max(find(i+1,j,row,col,matrix,dp),max(find(i+1,j-1,row,col,matrix,dp),find(i+1,j+1,row,col,matrix,dp)));

}
*/
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row=matrix.size();
    int col=matrix[0].size();
    /*Bottom UP-TC=O(row*col) SC=O(row*col)
    vector<vector<int>> dp(row,vector<int>(col,-1));
    int m=INT_MIN;
    for(int i=row-1;i>=0;i--)
    {
        for(int j=0;j<col;j++)
        {
            if(i==row-1)dp[i][j]=matrix[i][j];
            else
            {
                int left=INT_MIN,right=INT_MIN,down=INT_MIN;
                if(j>0)
                    left=dp[i+1][j-1];
                if(j<col-1)
                    right=dp[i+1][j+1];
                down=dp[i+1][j];
                dp[i][j]=matrix[i][j]+max(left,max(right,down));
            }
        }
    }
    for(int j=0;j<col;j++)
    {
        m=max(m,dp[0][j]);
    }
    return m;
    */

    //space optimization TC=O(row*col) SC=O(col)
    vector<int> dummy(col,-1);
    vector<int> dp(col);
    int m=INT_MIN;
    for(int i=row-1;i>=0;i--)
    {
        for(int j=0;j<col;j++)
        {
            if(i==row-1)dp[j]=matrix[i][j];
            else
            {
                int left=INT_MIN,right=INT_MIN,down=INT_MIN;
                if(j>0)
                    left=dummy[j-1];
                if(j<col-1)
                    right=dummy[j+1];
                down=dummy[j];
                dp[j]=matrix[i][j]+max(left,max(right,down));
            }
        }
        dummy=dp;
    }
    for(int j=0;j<col;j++)
    {
        m=max(m,dp[j]);
    }
    return m;

}
