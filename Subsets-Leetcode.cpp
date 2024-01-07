class Solution {
public:
    void find(int ind,vector<int>& nums,vector<vector<int>> &res,vector<int> &temp)
    {
        res.push_back(temp);
        for(int i=ind;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            find(i+1,nums,res,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        find(0,nums,res,temp);
        return res;
    }
};
