    bool DFS(int node,vector<int> adj[],vector<int> &visit,vector<int> &path)
    {
        visit[node]=1;
        path[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visit[adj[node][i]])//if it is not visited
            {
                if(DFS(adj[node][i],adj,visit,path))
                    return 1;
            }
            else if(path[adj[node][i]])//if it is already visited and it is in the path then cycle
            {
                return 1;
            }
        }
        path[node]=0;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visit(V,0);
        vector<int> path(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visit[i])
            {
                if(DFS(i,adj,visit,path))
                    return 1;
            }
        }
        return 0;
    }
