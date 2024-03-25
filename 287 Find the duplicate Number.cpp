class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*app 1: TC=O(n2) SC=O(1)
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j&&n==nums[j])
                    return nums[i];
            }
        }
        return -1;
        */

        /*TC=O(nlogn) SC=O(1)
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                return nums[i];
        }
        return -1;
        */

        /*TC=O(n) SC=O(n)
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
                return nums[i];
            s.insert(nums[i]);
        }
        return -1;
        */
        //TC=O(n) SC=O(1)
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
