class Solution {
public:
    int find(int i,vector<int> &nums)
    {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int m=(s+e)/2;
            if(nums[m]==i)
                return 1;
            else if(nums[m]<i)
                s=m+1;
            else
                e=m-1;
        }
        return 0;
    }
    int firstMissingPositive(vector<int>& nums) {
        /*Brute force TC=O(n2) sc=O(1)
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            int f=0;
            for(int j=0;j<n;j++)
            {
                if(i==nums[j])
                    f=1;
            }
            if(f==0)
                return i;
        }
        return n+1;
        */
        /*TC=O(n) SC=O(n)
        unordered_set<int> s;
        for(auto i:nums)
        {
            s.insert(i);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(s.find(i)==s.end())
                return i;
        }
        return nums.size()+1;
        */
        /*SOrting+binary search TC=O(nlogn) SC=O(1)
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++)
        {
            if(!find(i,nums))
                return i;
        }  
        return nums.size()+1;
        */

        //TC=O(n) SC=O(1)
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>=1&&nums[i]<=n&&nums[i]!=nums[nums[i]-1])//suppose index 0 has ele 3 ,it should be present at index 2 ,so we need to swap
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i+1==nums[i])
                continue;
            return i+1;
        }
        return n+1;
    }
};
