class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        //Approach 1:using queue :BFS
        /*
        queue<int> q;
        q.push(1);
        int node;
        int steps=-1;
        while(!q.empty())
        {
            steps++;
            int s=q.size();
            while(s--)
            {
                node=q.front();
                q.pop();
                if(node==n)
                    return steps;
                q.push(node+1);
                q.push(node*3);
            }
            
        }
        return steps;
        */
        int steps=0;
        while(n>1)
        {
            steps++;
            if(n%3==0)
                n=n/3;
            else
                n=n-1;
        }
        return steps;
    }
};
