class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //TC=O(Elogv) like in djkstras but we are not using priority queue so TC=O(E)=O(flights.size())
        vector<int> dis(n,1e9);//disrance from src to every other node
        dis[src]=0;
        //convert into adjacency list
        vector<pair<int,int>> l[n];
        for(auto it:flights)
        {
            l[it[0]].push_back({it[1],it[2]});
        }
        //queue store stops,node,distance
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            q.pop();
            if(stops>k)
                continue;
            for(auto i: l[node])
            {
                int adjnode=i.first;
                int cost=i.second;
                if(dist+cost<dis[adjnode])
                {
                    dis[adjnode]=dist+cost;
                    q.push({stops+1,{adjnode,cost+dist}});
                }
            }
        }
        if(dis[dst]==1e9)
            return -1;
        else    
            return dis[dst];
    }
};
