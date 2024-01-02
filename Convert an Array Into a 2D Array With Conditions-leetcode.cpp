class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        //TC=O(n) SC=O(n)
        unordered_map<int,int> m;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
                m[nums[i]]++;
                maxi=max(maxi,m[nums[i]]);
        }
        vector<vector<int>> res(maxi);
        for(auto it:m)
        {
            int num=it.first;
            int freq=it.second;
            for(int i=0;i<freq;i++)
                res[i].push_back(num);
        }
        return res;
    }
};
