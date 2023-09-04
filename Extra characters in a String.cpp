class Solution {
public:
    unordered_set<string> set;
    int n;
    int dp[51];
    int find(int index,string s)
    {
        if(dp[index]!=-1)
            return dp[index];
        string curr="";
        int minextra=INT_MAX;
        if(index>=n)
            return 0;
        for(int i=index;i<n;i++)
        {
            
            curr.push_back(s[i]);
            int currextra=(set.find(curr)==set.end())?curr.length():0;
            int nextextra=find(i+1,s);
            minextra=min(minextra,currextra+nextextra);
        }
        return dp[index]=minextra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        n=s.length();
        for(string s1:dictionary)
        {
            set.insert(s1);

        }   
        return find(0,s);
             
    }
};
