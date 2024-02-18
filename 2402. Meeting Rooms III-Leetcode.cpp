class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //TC=O(mlogm) SC=O(n)
        vector<int> roombookedcount(n,0);
        set<int> s;//to store available rooms
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;//stores endtime,roomno.
        sort(meetings.begin(),meetings.end());//sort meetings on start time
        for(int i=0;i<n;i++)
        {
            s.insert(i);//initially all rooms are available
        } 
        for(int i=0;i<meetings.size();i++)
        {
            long long start=meetings[i][0];
            long long end=meetings[i][1];
            while(q.size()>0&&q.top().first<=start)//pop meetings from queue
            {   
                int room =q.top().second;
                s.insert(room);
                q.pop();
            }
            if(s.size()==0)//no room available delay the meetings
            {
                pair<long long,int> pp=q.top();//gets end,roomno of meeting having lowest endtime
                q.pop();
                long long diff=end-start;//meeting rescheduled again should have same diff
                start=pp.first;//gives endtime of poped meeting ,it should be now starttime of this curr meeting  
                end=start+diff;
               
                s.insert(pp.second);

            }
            auto it=s.begin();
            q.push({end,*it});
            roombookedcount[*it]++;//increase the booking count of the room
            s.erase(*it);//get the least available room and delete it from set
            
        }
        int maxbook=0,room=0;
        for(int i=0;i<n;i++)
        {
            if(roombookedcount[i]>maxbook)
            {
                room=i;
                maxbook=roombookedcount[i];
            }
        }
        return room;
    }
};
