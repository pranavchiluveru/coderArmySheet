//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph
	void togologicalSort(vector<vector<int>>& adj,int node,vector<int> &visit,stack<int> &s)
	{
	        visit[node]=1;
	        for(int i=0;i<adj[node].size();i++)
	        {
	            if(!visit[adj[node][i]])
	            {
	                togologicalSort(adj,adj[node][i],visit,s);
	            }
	        }      
	        s.push(node);
	    
	}
	void DFS(vector<vector<int>>& reverse,int node,vector<int> &visited)
	{
	    visited[node]=1;
	    for(int i=0;i<reverse[node].size();i++)
	    {
	        if(!visited[reverse[node][i]])
	        {
	            DFS(reverse,reverse[node][i],visited);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //topological sort
        vector<int> visit(V,0);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!visit[i])
            {
                togologicalSort(adj,i,visit,s);
            }
        }
        
        
        //reverse edges
        vector<vector<int>> reverse(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                reverse[adj[i][j]].push_back(i);
            }
        }
        //dfs
        vector<int> visited(V,0);
        int count=0;
        while(!s.empty())
        {
            if(!visited[s.top()])
            {
                count++;
                DFS(reverse,s.top(),visited);
            }
            s.pop();
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
