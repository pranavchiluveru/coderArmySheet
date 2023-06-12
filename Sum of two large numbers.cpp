//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string x, string y) {
        // Your code goes here
        int n=x.size();
        int m=y.size();
        int i=n-1,j=m-1;
        string ans="";
        int carry=0;
        while(i>=0 || j>=0|| carry>0)
        {
            int d1=(i>=0)?x[i--]-'0':0;
            int d2=(j>=0)?y[j--]-'0':0;
            int sum=d1+d2+carry;
            carry=sum/10;
            sum=sum%10;
            ans+=('0'+sum);
        }
        reverse(ans.begin(),ans.end());
        //removing leading zeros and not last zero
        i=0;
        while(i<ans.size()-1&&ans[i]=='0')
            i++;
        return ans.substr(i);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends
