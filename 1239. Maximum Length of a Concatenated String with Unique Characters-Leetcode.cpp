class Solution {
public:
    unordered_map<string,int> dp;
    bool uniquecharacters(string s1,string s2)
    {
        unordered_set<char> sset;
        for(int i=0;i<s1.size();i++)
        {
            if(sset.find(s1[i])!=sset.end())
                return false;
            sset.insert(s1[i]);
        }
        for(int i=0;i<s2.size();i++)
        {
            if(sset.find(s2[i])!=sset.end())
                return false;
            sset.insert(s2[i]);
        }
        return true;
    }
    int find(int i,vector<string>& arr,int n,string temp)
    {
        if(i==n)
            return temp.length();
        if(dp.find(temp)!=dp.end())
            return dp[temp];
        int include=0;
        int exclude=0;
        if(!uniquecharacters(temp,arr[i]))
        {
            exclude=find(i+1,arr,n,temp);
        }
        else
        {
            exclude=find(i+1,arr,n,temp);
            include=find(i+1,arr,n,temp+arr[i]);
        }
        
        return dp[temp]=max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return find(0,arr,n,temp);  
    }
};
