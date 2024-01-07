class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int> f1,f2;
        for(auto i:nums1)
        {
            f1[i]++;
        }
        for(auto i:nums2)
        {
            f2[i]++;
        }
        int only_in_f1=0,only_in_f2=0,both=0;
        for(auto i:f1)
        {
            if(f2.find(i.first)!=f2.end())
                both++;
            else
                only_in_f1++;
        }
        for(auto i:f2)
        {
            if(f1.find(i.first)==f1.end())
                only_in_f2++;
        }
        only_in_f1=min(only_in_f1,n/2);
        only_in_f2=min(only_in_f2,n/2);
        if(only_in_f1<n/2)
        {
            int req=n/2-only_in_f1;
            int has=min(both,req);
            both-=has;
            only_in_f1+=has;
        }
        if(only_in_f2<n/2)
        {
            int req=n/2-only_in_f2;
            int has=min(both,req);
            both-=has;
            only_in_f2+=has;
        }
        return only_in_f1+only_in_f2;
    }
};
