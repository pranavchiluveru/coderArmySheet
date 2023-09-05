class Solution {
public:
    int Gardensize;
    map<pair<int,int>,int> dp;//pair<index,maxEnd> int:res
    int solve(int index,vector<pair<int,int>> &limits,int maxEnd)
    {
        if(dp.find({index,maxEnd})!=dp.end())
        {
            return dp[{index,maxEnd}];
        }
        if(index>=limits.size()){
            if(maxEnd>=Gardensize)
            {
                return 0;
            }
            else
            {
                return 1e9;
            }
        }
        if(limits[index].first>maxEnd)
        {
            return 1e9;
        }
        int open    = 1+solve(index+1,limits,max(maxEnd,limits[index].second));
        int not_open= solve(index+1,limits,maxEnd);
        return dp[{index,maxEnd}]=min(open, not_open);
    }
    int minTaps(int n, vector<int>& ranges) {
        Gardensize=n;
        vector<pair<int,int>> limits;
        for(int i=0;i<ranges.size();i++)
        {
            int start=max(0,i-ranges[i]);
            int end  =min(n,i+ranges[i]);
            limits.push_back({start,end});

        }
        int maxEnd=0;
        sort(begin(limits),end(limits));
        int res=solve(0,limits,maxEnd);
        return res>=1e9?-1:res;
    }
};
