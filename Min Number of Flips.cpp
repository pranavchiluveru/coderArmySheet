//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n=S.size();
    int flips1=0,flips2=0;
    int temp=0;//comparing with 01010101....
    for(int i=0;i<n;i++)
    {
        if(S[i]-'0'!=temp)
            flips1++;
        temp=!temp;//temp^=1;
    }
    temp=1;//comparing with 101010101010....
    for(int i=0;i<n;i++)
    {
        if(S[i]-'0'!=temp)
            flips2++;
        temp=!temp;//temp^=1;
    }
    
    return min(flips1,flips2);   
}
