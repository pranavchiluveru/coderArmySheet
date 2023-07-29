//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // priority queue with pair ordered by first element(min) at top
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;
        vector<int> res(V,-1);
        //distance,node
        q.push({0,S});
        while(!q.empty())
        {
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();//top element is removed
            //as soon as it poped out of queue check if is visted[result is finalised or not]
            if(res[node]==-1)//res -1 means not visted 
                res[node]=dis;//its result is finalised .now it is considered as visited
            else//means it is already visited so do nothing goto next element in queue
                continue;
            for(int i=0;i<adj[node].size();i++)
            {
                //check if adjacent nodes are visited
                if(res[adj[node][i][0]]==-1)//means not visited
                {
                    q.push({dis+adj[node][i][1],adj[node][i][0]});
                }
            }
        }
        return res;
    }
