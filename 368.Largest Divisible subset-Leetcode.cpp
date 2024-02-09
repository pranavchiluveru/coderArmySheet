class Solution {
public:
    /*Recursion TC=O(2^n)
    vector<int> ans;
    void find(int ind,vector<int>& nums,vector<int> &res,int prev)
    {
        if(ind==nums.size())
        {
            if(res.size()>ans.size())
            {
                ans=res;
            }
            return;
        }
        if(prev==-1||nums[ind]%prev==0)
        {
            res.push_back(nums[ind]);
            find(ind+1,nums,res,nums[ind]);
            res.pop_back();
        }
    
        find(ind+1,nums,res,prev);
    }
    */
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        //find(0,nums,res,-1);
        //return ans;

        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>());
        

        for (int i = 0; i < n; ++i) {
            dp[i] = {nums[i]};

            for (int j = i-1; j >=0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j].size() >= dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
        }

        vector<int> result;
        for (auto& subset : dp) {
            if (subset.size() > result.size()) {
                result = subset;
            }
        }

        return result;
        
        
    }
};
