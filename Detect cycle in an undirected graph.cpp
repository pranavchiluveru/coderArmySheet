 bool detectCycleUsingDFS(vector<int> adj[],int node,int parent,vector<bool> &visited)
    {
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                if(detectCycleUsingDFS(adj,adj[node][i],node,visited))
                    return 1;
            }
            else if(parent!=adj[node][i])
                return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycleUsingDFS(adj,i,-1,visited))
                    return 1;
            }
        }
        return 0;
        
    }
