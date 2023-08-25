//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int printfib(int n,vector<int> &res)
    {
        if(res[n]!=-1)
            return res[n];
        if(n==0)
            return res[0]=1;
        if(n==1)
            return res[1]=1;
        return res[n]=(printfib(n-1,res)+printfib(n-2,res))%1000000007;
    }
    int nthFibonacci(int n){
        // code here
        vector<int> res(n,-1);
        return printfib(n-1,res);
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
