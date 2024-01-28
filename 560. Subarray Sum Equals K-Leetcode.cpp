class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*brute force TC=O(n^2) SC=O(n)
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==k)
                    count++;
                
            }
        }
        return count;
        */
        //using prefix sum TC=O(n) SC=O(n)
      //see solutions section in leetcode for explanation: aryanttripathi
        int n=nums.size();
        int prefix[n];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int> mpp;//store element and occurance
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i]==k)
                count++;
            if(mpp.find(prefix[i]-k)!=mpp.end())
                count+=mpp[prefix[i]-k];
            mpp[prefix[i]]++;
        }
        return count;
    }
};
