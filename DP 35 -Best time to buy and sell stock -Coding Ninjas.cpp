#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int maxdiff=0;
    /*Brute force TC=O(n^2) Sc=O(1)
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(prices[j]-prices[i]>maxdiff)
                maxdiff=prices[j]-prices[i];
        }
    }
    return maxdiff;
    */
    TC=O(n) Sc=O(1)
    int minele=prices[0];
    for(int i=1;i<n;i++)
    {
        if(prices[i]>minele)
            maxdiff=max(maxdiff,prices[i]-minele);
        else
            minele=prices[i];
    }
    return maxdiff;
}
