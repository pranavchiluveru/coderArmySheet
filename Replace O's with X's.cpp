  int check(int i,int j,int n,int m)
    {
        return i>-1&&j>-1&&i<n&&j<m;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int row[4]={-1,1,0,0};
        int col[4]={0,0,1,-1};
        vector<vector<char>> res(n,vector<char>(m,'X'));
        vector<vector<int>> visit(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0||i==n-1||j==0||j==m-1)&&mat[i][j]=='O')
                {
                    q.push({i,j});
                    visit[i][j]=1;
                    res[i][j]='O';
                }
            }
        }
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(check(i+row[k],j+col[k],n,m)&&!visit[i+row[k]][j+col[k]]&&mat[i+row[k]][j+col[k]]=='O')
                {
                    res[i+row[k]][j+col[k]]='O';
                    q.push({i+row[k],j+col[k]});
                    visit[i+row[k]][j+col[k]]=1;
                }
            }
        }
        return res;
    }
