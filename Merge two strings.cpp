//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string s1, string s2)
{
    // your code here
    int n=s1.size();
    int m=s2.size();
    int i=0,j=0;
    string s3="";
    while(i<n&&j<m)
    {
            s3+=s1[i];
            i++;
            s3+=s2[j];
            j++;
        
    }
    while(i<n)
    {
        s3+=s1[i];
        i++;
    }
    while(j<m)
    {
        s3+=s2[j];
        j++;
    }
    return s3;
}
