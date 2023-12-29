class Solution {
public:
    //TC=O(n*d) sc=O(n*d)
    int find(int i,vector<int>& jobDifficulty, int d,int n,vector<vector<int>> &dp)
    {
        if(d==1)
            return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
        int maxele=INT_MIN,res=INT_MAX;
        if(dp[i][d]!=-1)return dp[i][d];
        for(int j=i;j<=n-d;j++)
        {
            maxele=max(maxele,jobDifficulty[j]);
            res=min(maxele+find(j+1,jobDifficulty,d-1,n,dp),res);
        }
        return dp[i][d]=res;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
       
        int n=jobDifficulty.size();
        if(n<d)return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return find(0,jobDifficulty,d,n,dp);
        
    }
};
