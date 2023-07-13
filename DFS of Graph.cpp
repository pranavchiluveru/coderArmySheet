// Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> adj[],int* visited,vector<int> &ans)
    {
        visited[node]=1;
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                dfs(adj[node][i],adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        vector<int> ans;
        dfs(0,adj,visited,ans);
        return ans;
    }
