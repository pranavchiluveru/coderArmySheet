class Solution {
public:
    struct job
    {
        int start;
        int end;
        int profit;
    };
    bool static comparator(struct job j1,struct job j2)
    {
        if(j1.start<j2.start)return true;
        return false;
    }
    int nextele(int i,struct job j[],int n,int endlimit)
    {
        int start=i,end=n-1;
        int index=n+1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(j[mid].start>=endlimit)
            {
                end=mid-1;
                index=mid;
            }
            else
            {
                start=mid+1;
            }
        }
        return index;
    }
    int find(int i,struct job j[],int n,vector<int> &dp)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int nextindex=nextele(i+1,j, n,j[i].end);//takes O(logn) time
        int taken=j[i].profit+find(nextindex,j,n,dp);
        int not_taken=find(i+1,j,n,dp);
        return dp[i]=max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //TC=O(nlogn) SC=O(n)
        int n=startTime.size();
        struct job j[n];
        for(int i=0;i<n;i++)
        {
            j[i].start=startTime[i];
            j[i].end=endTime[i];
            j[i].profit=profit[i];
        }
        sort(j,j+n,comparator);
        vector<int> dp(n+1,-1);
        return find(0,j,n,dp);
    }
};
