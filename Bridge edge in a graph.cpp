 //Function to find if the given edge is a bridge in graph.
    bool DFS(int node, int target,vector<int> adj[], vector<int> &visit)
    {
        if(node==target)
            return 1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visit[adj[node][i]])
            {
                visit[adj[node][i]]=1;
                if(DFS(adj[node][i],target,adj,visit))
                    return 1;
            }
        }
        return 0;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        for(int i=0;i<adj[c].size();i++)
        {
            if(adj[c][i]==d)
            {
                adj[c][i]=c;
            }
        }
        for(int i=0;i<adj[d].size();i++)
        {
            if(adj[d][i]==c)
            {
                adj[d][i]=d;
            }
        }
        vector<int> visit(V,0);
        visit[c]=1;
        return !DFS(c,d,adj,visit);
    }
