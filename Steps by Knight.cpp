//Function to find out minimum steps Knight needs to reach target position.
    int check(int i,int j,int n)
    {
        return i>0&&i<=n&&j>0&&j<=n;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    /*
	    vector<vector<int>> matrix(N+1,vector<int>(N+1,0));
	    int row[8]={1,2,2,1,-1,-2,-2,-1};
	    int col[8]={-2,-1,1,2,2,1,-1,-2};
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    matrix[KnightPos[0]][KnightPos[1]]=1;
	    if(KnightPos[0]==TargetPos[0]&&KnightPos[1]==TargetPos[1])
	        return 0;
	    int steps=0;
	    while(!q.empty())
	    {
	        steps++;
	        int size=q.size();
	        while(size--)
	        {
	        
	        for(int k=0;k<8;k++)
	        {
	            if(check(i+row[k],j+col[k],N)&&matrix[i+row[k]][j+col[k]]==0)
	            {
	                if(i+row[k]==TargetPos[0]&&j+col[k]==TargetPos[1])
	                    return steps;
	                matrix[i+row[k]][j+col[k]]=1;
	                q.push({i+row[k],j+col[k]});
	            }
	        }
	        }
	    }
	    return -1;
	    */
	    //efficient code
	    vector<vector<int>> matrix(N+1,vector<int>(N+1,0));
	    int row[8]={1,2,2,1,-1,-2,-2,-1};
	    int col[8]={-2,-1,1,2,2,1,-1,-2};
	    queue<pair<pair<int,int>,int>> q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    matrix[KnightPos[0]][KnightPos[1]]=1;
	    while(!q.empty())
	    {
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int step=q.front().second;
	        if(i==TargetPos[0]&&j==TargetPos[1])
	            return step;
	        q.pop();
	        for(int k=0;k<8;k++)
	        {
	            if(check(i+row[k],j+col[k],N)&&matrix[i+row[k]][j+col[k]]==0)
	            {
	                matrix[i+row[k]][j+col[k]]=1;
	                q.push({{i+row[k],j+col[k]},step+1});
	            }
	        }
	    }
	    return -1;
	}
