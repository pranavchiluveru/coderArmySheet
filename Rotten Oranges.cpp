    bool check(int i,int j,int n,int m)
    {
        return i>-1&&i<n&&j>-1&&j<m;
    }
    int BFS(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>> q,int n,int m,int &goodOranges)
    {
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        int timer=0;
        while(!q.empty())
        {
            
            int i=q.front().first.first;
            int j=q.front().first.second;
            timer=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(check(i+row[k],j+col[k],n,m)&&grid[i+row[k]][j+col[k]]==1)
                {
                    grid[i+row[k]][j+col[k]]=0;
                    goodOranges--;
                    q.push({{i+row[k],j+col[k]},timer+1});
                }
            }
            
        }
        if(goodOranges) return -1;
        else return timer;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int goodOranges=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    goodOranges++;
                    
                }
                else if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        return BFS(grid,q,n,m,goodOranges);
    
    }
