class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       
       int mod=1e9+7;
        //watch youtube video codestorywithmik
       /*Brute force TC=O(n^2) SC=O(1)
       long long sumele=0;
       for(int i=0;i<arr.size();i++)
       {
           int minele=INT_MAX;
           for(int j=i;j<arr.size();j++)
           {
               minele=min(minele,arr[j]);
               sumele+=minele;
           }
       } 
       return (sumele)%mod;
       */
      //optimal Approach TC=O(n) SC=O(n)
       int n=arr.size();
       vector<int> nsl(n);//next smaller element to left
       stack<int> st1;
       for(int i=0;i<n;i++)
       {
            if(st1.empty())
                nsl[i]=-1;
            else
            {
                while(!st1.empty()&&arr[st1.top()]>=arr[i]) // >=
                    st1.pop();
                nsl[i]=st1.empty()?-1:st1.top();
            }
            st1.push(i);
       }
       vector<int> nsr(n);//next smaller element to right
       stack<int> st2;
       for(int i=n-1;i>=0;i--)
       {
            if(st2.empty())
                nsr[i]=n;
            else
            {
                while(!st2.empty()&&arr[st2.top()]>arr[i])  //just > to eliminate duplicates
                    st2.pop();
                nsr[i]=st2.empty()?n:st2.top();
            }
            st2.push(i);
       }
       long long sumele=0;
       for(int i=0;i<n;i++)
       {
           int l=i-nsl[i];
           int r=nsr[i]-i;
           long long noofsubarrays=(l*r); //we get number of subarrays where arr[i] is minimum 
           long long totalsum=noofsubarrays*arr[i];
           sumele=(sumele+totalsum)%mod;
       }
        return sumele;
    }
};
