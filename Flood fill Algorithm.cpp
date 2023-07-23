bool check(int i,int j,int n,int m)
    {
        return i>-1&&i<n&&j>-1&&j<m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int row[4]={0,0,-1,1};
        int col[4]={-1,1,0,0};
        int n=image.size();
        int m=image[0].size();
        int startColor=image[sr][sc];
        image[sr][sc]=newColor;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<bool>> visit(n,vector<bool>(m,0));
        visit[sr][sc]=1;
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(check(i+row[k],j+col[k],n,m)&&!visit[i+row[k]][j+col[k]])
                {
                    
                    visit[i+row[k]][j+col[k]]=1;
                    if(image[i+row[k]][j+col[k]]==startColor){
                        image[i+row[k]][j+col[k]]=newColor;
                        q.push({i+row[k],j+col[k]});
                    }
                }
            }
        }
        return image;
    }
