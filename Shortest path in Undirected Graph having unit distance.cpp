vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> res(N,-1);
        vector<int> adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        res[src]=0;
        while(!q.empty())
        {
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                if(res[adj[node][i]]==-1)
                {
                    res[adj[node][i]]=dis+1;
                    q.push({adj[node][i],dis+1});
                }
            }
        }
        return res;
    }
