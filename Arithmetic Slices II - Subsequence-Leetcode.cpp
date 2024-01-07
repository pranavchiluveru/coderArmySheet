class Solution {
public:
    /*Brute force
    int n=0;
    bool checkAP(vector<int> arr)
    {
        sort(arr.begin(),arr.end());
        long long diff=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if((long long)arr[i]-arr[i-1]!=diff)
                return false;
        }
        return true;
    }
    void findsubsets(int ind,vector<int>& nums,vector<int> &temp)
    {
        if(temp.size()>=3)
        {
            if(checkAP(temp))
                n++;
        }
        for(int i=ind;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            findsubsets(i+1,nums,temp);
            temp.pop_back();
        }
    }
    */
    int numberOfArithmeticSlices(vector<int>& nums) {
        /*Brute Force -TC=O(2^n*n)
        vector<int> temp;
        findsubsets(0,nums,temp);
        return n;
        */
        //optimal approach TC=O(n^2) SC=O(n)
        int n=nums.size();
        int res=0;
        unordered_map<long,int> arr[n];//array of map which stores diff and count
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long diff=(long)nums[i]-nums[j];
                int count_at_j=0;
                if(arr[j].find(diff)!=arr[j].end())
                {
                    count_at_j=arr[j][diff];
                }
                arr[i][diff]+=1+count_at_j;
                res+=count_at_j;
            }
        }
        return res;
    }
    
};
