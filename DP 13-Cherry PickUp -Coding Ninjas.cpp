#include <bits/stdc++.h>
//Top Down -TC=O(r*c*c)*9     SC=O(r*c*c)+O(r)
int find(int i,int j1,int j2,int r,int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(j1<0||j1>=c||j2<0||j2>=c)return INT_MIN;
    if (i == r - 1)
    {
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
       
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

    int m=0;
    if(j1==j2)m=grid[i][j1];
    else m=grid[i][j1]+grid[i][j2];
    
    int maxi=INT_MIN;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int val=0;
            val+=find(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            maxi=max(maxi,val);
        }
        
    }
    
    
    return dp[i][j1][j2]=m+maxi;
} 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    //dp[i][j1][j2]
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    int x=find(0,0,c-1,r,c,grid,dp);
    return x;
}
