#include<bits/stdc++.h>
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //TC=O(n) sc=O(n)
        int n=words.size();
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                freq[words[i][j]]++;
            }
        }
        for(auto it:freq)
        {
            if(it.second%n!=0)
                return false;
        }
        return true;
    }
};
