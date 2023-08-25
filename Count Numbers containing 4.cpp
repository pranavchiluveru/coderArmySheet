//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool contains4(int n,vector<bool> &dp)
    {
        while(n>0)
        {
            if(dp[n])
                return 1;
            int rem=n%10;
            if(rem==4)
                return 1;
            n=n/10;
        }
        return 0;
    }
    int countNumberswith4(int N) {
        // code here
        int count=0;
        vector<bool> dp(N+1,0);
        for(int i=1;i<=N;i++)
        {
            if(contains4(i,dp))
            {
                dp[i]=1;
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
