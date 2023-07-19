   bool check(int i,int j,int n,int m)
    {
        return i>-1&&i<n&&j>-1&&j<m;
    }
    void BFS(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        int row[8]={-1,-1,0,1,1,1,0,-1};//for 8 directions
        int col[8]={0,-1,-1,-1,0,1,1,1};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<8;k++)
            {
                if(check(i+row[k],j+col[k],n,m)&&grid[i+row[k]][j+col[k]]=='1')
                {
                    grid[i+row[k]][j+col[k]]='0';
                    q.push({i+row[k],j+col[k]});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int c=0;//count of islands
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')
            {
                c++;
                grid[i][j]='0';
                BFS(grid,i,j,n,m);
            }
        }
        return c;
    }
