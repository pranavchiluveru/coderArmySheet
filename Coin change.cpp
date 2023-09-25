//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    /*Recursion
    long long int find(int i,int n,int coins[],int sum)
    {
        if(sum==0)
            return 1;
        if(sum<0)
            return 0;
        if(i>=n)
            return 0;
        long long int include,exclude;
        include=find(i,n,coins,sum-coins[i]);
        exclude=find(i+1,n,coins,sum);
        return include+exclude;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        return find(0,N,coins,sum);
    }
    
    */
    //DP Top Down
    long long int find(int i,int n,int coins[],int sum,vector<vector<long long int>> &dp)
    {
        if(sum==0)
            return 1;
        if(sum<0||i>=n)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        long long int include=find(i,n,coins,sum-coins[i],dp);
        long long int exclude=find(i+1,n,coins,sum,dp);
        return dp[i][sum]=include+exclude;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
        return find(0,N,coins,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
