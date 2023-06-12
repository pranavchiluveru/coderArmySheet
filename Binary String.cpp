//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        
        // Your code here
        long count=0;
        /*
        Approach 1:Brute force:O(n2)
        for(int i=0;i<n;i++)
        {
            if(a[i]=='0')
                continue;
            for(int j=i+1;j<n;i++)
            {
                if(a[j]=='1')
                    count++;
            }
        }
        return count;
        
        Approach 2: O(n) Counting Approach
        long right_ones=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]=='0')
                continue;
            right_ones+=count;
            count++;
        }
        return right_ones;
        */
        //Approach 3:o(n) Mathematical combinations
        for(int i=0;i<n;i++)
        {
            if(a[i]=='1')
                count++;
        }
        count=(count*(count-1))/2;
        return count;
    }

};

//{ Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}

// } Driver Code Ends
