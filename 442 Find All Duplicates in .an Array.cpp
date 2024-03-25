class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*TC=O(n2) SC=O(n)
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j&&nums[i]==nums[j])
                {
                    s.insert(nums[i]);
                }
            }
        }
        return vector<int>(s.begin(),s.end());
        */
        /*TC=O(n) SC=O(n)
        set<int> s;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                res.push_back(nums[i]);
            }
            else
                s.insert(nums[i]);
        }
        return res;
        */
        /*TC=O(nlogn) SC=O(1)
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                res.push_back(nums[i]);
            }
        }
        return res;
        */
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int x=abs(nums[i]);
            if(nums[x-1]<0)
            {
                res.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return res;
    }
};
