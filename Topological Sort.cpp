public:
	/*
	void DFS(int node,vector<int> adj[],vector<int> &visit,stack<int> &res)
	{
	    visit[node]=1;
	    for(int i=0;i<adj[node].size();i++)
	    {
	        if(!visit[adj[node][i]])
	        {
	            DFS(adj[node][i],adj,visit,res);
	        }
	    }
	    res.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> res;
	    vector<int> visit(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!visit[i])
	        {
	            DFS(i,adj,visit,res);
	        }
	    }
	    vector<int> ans;
	    while(!res.empty())
	    {
	        ans.push_back(res.top());
	        res.pop();
	    }
	    return ans;
	    
	}
	*/
	//khans Algorithm
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> inDegree(V,0);
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            inDegree[adj[i][j]]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(inDegree[i]==0)
	            q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(int i=0;i<adj[node].size();i++)
	        {
	            inDegree[adj[node][i]]--;
	            if(inDegree[adj[node][i]]==0)
	                q.push(adj[node][i]);
	        }
	    }
	    return ans;
	}
	
