vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // dijkstras algorithm
        vector<int> res(N,-1);
        //priority queue of pair ordered by first(min)at top
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        //dis,node
        q.push({0,0});
        while(!q.empty())
        {
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
            //as soon as it poped check if its result is already updated(visited)
            if(res[node]==-1)//not updated
            {
                res[node]=dis;//update it
            }
            else// updated already(visted)
            {
                continue;//goto next element in queue
            }
            for(int i=0;i<M;i++)
            {
                if(edges[i][0]==node&& res[edges[i][1]]==-1)//see adjacent nodes of node and check it they are visted or not 
                {
                    q.push({dis+edges[i][2],edges[i][1]});
                }
            }
        }
        return res;
    }
