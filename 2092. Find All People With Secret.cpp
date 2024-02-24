class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> vis(n,0);
        vector<pair<int,int>> vec[n];
        for(auto it:meetings)
        {
            vec[it[0]].push_back({it[1],it[2]});
            vec[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//time ,person
        q.push({0,0});
        q.push({0,firstPerson});
        while(!q.empty())
        {
            auto i=q.top();
            q.pop();
            int time=i.first;
            int per=i.second;
            if(vis[per])
                continue;
            vis[per]=1;
            for(auto adj:vec[per])
            {
                if(!vis[adj.first]&&time<=adj.second)
                    q.push({adj.second,adj.first});
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
