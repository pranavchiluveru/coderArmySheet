//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int i;
        int siz=str1.size();
        //clockwise 2 places
        for(i=0;i<siz;i++)
        {   
            if(str1[i]!=str2[(i+2)%siz])
                break;
            
        }
        if(i==siz)
            return 1;
        //anti-clockwise 2 places
        for(i=0;i<siz;i++)
        {
            if(str1[i]!=str2[(i+siz-2)%siz])
                break;
        }
        if(i==siz)
            return 1;
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends
