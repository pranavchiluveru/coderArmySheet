void DFS(vector<vector<int>> &adj, int node,vector<bool> &visited)
    {
        if(visited[node])return;
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(adj[node][i]&& node!=i)
                DFS(adj,i,visited);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,0);
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                count++;
                DFS(adj,i,visited);
            }
        }
        return count;
    }
