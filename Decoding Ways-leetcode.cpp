#include<bits/stdc++.h>
#include<map>
using namespace std;
class Solution {
public:
    /*mysolution
    int decode(string s,map<string,char> &mymap,map<string,int> &memo)
    {
        int c1=0,c2=0;
        if(s.empty())
            return 1;
        if(memo.find(s)!=memo.end())return memo[s];
        auto it1=mymap.find(s.substr(0,1));
        if(it1!=mymap.end())
            c1=decode(s.substr(1),mymap,memo);
        if(s.length()>=2){
        auto it2=mymap.find(s.substr(0,2));
        if(it2!=mymap.end())
            c2=decode(s.substr(2),mymap,memo);
        }
        return memo[s]=c1+c2;
    }
    */
    int decode(string s,int index,vector<int> &dp)
    {
        if(index==s.length())
            return 1;
        if(dp[index]!=-1)return dp[index];
        if(s[index]=='0')
            return 0;
        int ways=0;
        ways+=decode(s,index+1,dp);
        if(index+1<s.length() && (s[index]=='1'||(s[index]=='2'&&s[index+1]<='6')))
            ways+=decode(s,index+2,dp);
        return dp[index]=ways;
    }
    int numDecodings(string s) {
        /*mysolution: memoization
        map<string,char> mymap;
        map<string,int> memo;
        for(int i=1;i<27;i++)
        {
            mymap[to_string(i)]='A'+i-1;
        }
        return decode(s,mymap,memo);
        */
        //optimal solution TC=O(n) SC=O(n)
        vector<int> dp(s.length(),-1);
        return decode(s,0,dp);
    }
};
