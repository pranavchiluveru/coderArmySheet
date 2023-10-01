#include<bits/stdc++.h>
/*Top-Down sc=dp vector+recursion stack=O(n*4)+o(n)  
TC=no of subproblems* time for each subproblem=O(n*3)*o(3)
int find(int currentDay,int lastDayIndex,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    if(currentDay==0)
    {
        int k=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(lastDayIndex!=i)
                k=max(k,points[0][i]);
        }
        return k;
    }
    if(dp[currentDay][lastDayIndex]!=-1)
        return dp[currentDay][lastDayIndex];
    int m=INT_MIN;
    for(int i=0;i<3;i++)
    { 
        if(i!=lastDayIndex)
        {
            m=max(m,points[currentDay][i]+find(currentDay-1,i,points,dp));
        }
    }
    return dp[currentDay][lastDayIndex]=m;
}
*/
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    /*greedy doesnt work
    int m,k=3,sum=0;
    for(int i=0;i<n;i++)
    {
        m=INT_MIN;
        for(int j=0;j<3;j++)
        {
            if(m<points[i][j]&&k!=j)
            {
                m=points[i][j];
            }

        }
        for(int j=0;j<3;j++)
        {
            if(m==points[i][j])
                k=j;
        }
        sum+=m;
    }
    return sum;
    */
    /*Top Down
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return find(n-1,3,points,dp);
    */

    /*Bottom Up TC=O(n*3*3) SC=O(n*3)
    vector<vector<int>> dp(n,vector<int>(3,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    for(int currentDay=1;currentDay<n;currentDay++)
    {
        for(int lastDayIndex=0;lastDayIndex<3;lastDayIndex++)
        {
            int m=INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                if(i!=lastDayIndex)
                    m=max(m ,points[currentDay][i] + dp[currentDay-1][i]);
            }
            dp[currentDay][lastDayIndex]=m;
        }
    }
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    */
    //space optimization TC=o(n*3*3) SC=O(3)
    vector<int> dp(3,-1);
    vector<int> dummy(3,-1);
    dp[0]=max(points[0][1],points[0][2]);
    dp[1]=max(points[0][0],points[0][2]);
    dp[2]=max(points[0][1],points[0][0]);
    for(int currentDay=1;currentDay<n;currentDay++)
    {
        for(int lastDayIndex=0;lastDayIndex<3;lastDayIndex++)
        {
            int m=INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                if(i!=lastDayIndex)
                    m=max(m ,points[currentDay][i] + dp[i]);
            }
            dummy[lastDayIndex]=m;
        }
        dp=dummy;
    }
    
    return max(dp[0],max(dp[1],dp[2]));

}
