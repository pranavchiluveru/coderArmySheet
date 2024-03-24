class Solution {
public:
/*
nums =[2,3,2,1]
freq =[3,2,-3,1]
res
i=0 ; mpp=[2,3] ; pq=[3,2] ;freq matches no need to pop anything  ;res[i]=3
i=1 ; mpp=[2,3][3,2];pq=[3,2] [2,3];freq matches no need to pop anything  ;res[i]=3
i=2 ; mpp=[2,0][3,2];pq=[3,2] [2,3] [0,2];pq.top().second gives ID=2 mpp[2]!=pq.top().first freq doesnt match implies values of ID =2 has been changd so pop it ; pq=[2,3] [0,2] pq.top().second gives ID=3 mpp[3]!=pq.top().first freq matches so no need to pop anything ; res[i]=2
i=3 ; mpp=[2,0][3,2][1,1]; pq=[2,3] [1,1] [0,2];pq.top().second gives ID=3 mpp[3]!=pq.top().first freq matches so no need to pop anything ; res[i]=2
*/
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<long long,long long> mpp; //ID,freq
        vector<long long> res(nums.size());
        priority_queue<pair<long long,long long>> pq;//freq,ID
        //TC=O(nlogn)
        for(long long i=0;i<nums.size();i++)
        {
            mpp[nums[i]]+=freq[i];
            pq.push({mpp[nums[i]],nums[i]});
            while(!pq.empty()&& mpp[pq.top().second]!=pq.top().first)//i.e if freq doesnt match it implies value has been changed ,so we need to pop
                pq.pop();
            res[i]=pq.top().first;
        }
        return res;
    }
};
