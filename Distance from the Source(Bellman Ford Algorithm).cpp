//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    
    */
    bool bellman(vector<vector<int>>& edges,vector<int> &dis)
    {
        //we will traverse all edges
        bool change=0;
        for(int i=0;i<edges.size();i++)
        {
            //dis[v]=min(dis[u]+edge_weight,dis[v])
            if(dis[edges[i][1]]>dis[edges[i][0]]+edges[i][2])
            {
                dis[edges[i][1]]=dis[edges[i][0]]+edges[i][2];
                change=1;
            }
        }
        return change;
    }
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        //for v vertices run bellman for v-1 times
        vector<int> dis(V,1e8);
        dis[S]=0;
        for(int i=0;i<V-1;i++)
        {
            if(!bellman(edges,dis))//if no change i.e dis is same as previous pass then return beacuse dis will not change
                return dis;
        }
        
        //run bellman for on more time to check negative cycle
        vector<int> v1;
        if(bellman(edges,dis))//dis changed means negative cycle
        {
            v1.push_back(-1);
            return v1;
        }
        
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
