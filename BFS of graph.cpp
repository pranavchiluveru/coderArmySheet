vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> ans;
        int visited[V]={0};
        q.push(0);
        visited[0]=1;
        int node;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                if(!visited[adj[node][i]])
                {
                    q.push(adj[node][i]);
                    visited[adj[node][i]]=1;
                }
            }
        }
        return ans;
}
