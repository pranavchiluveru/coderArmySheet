 // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> ans;
        int node=0;
        while(node!=V)
        {
            vector<int> row;
            row.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                row.push_back(adj[node][i]);
                
            }
            ans.push_back(row);
            node++;
        }
        return ans;
    }
