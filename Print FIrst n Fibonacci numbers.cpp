//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    long long findFibb(int n, vector<long long> &res)
    {
        if(res[n]!=-1)
            return res[n];
        if(n==0)
            return res[n]=1;
        if(n==1)
        {
            res[n-1]=1;
            return res[n]=1;
        }
        return res[n]=findFibb(n-1,res)+findFibb(n-2,res);
        
    }
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> res(n,-1);
        findFibb(n-1,res);
        res[0]=1;
        res[1]=1;
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends
