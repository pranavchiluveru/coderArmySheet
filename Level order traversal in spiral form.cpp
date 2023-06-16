//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    bool dir=0;//0->R to L
    vector<int> ans;
    if(!root)return ans;
    queue<Node *> q;
    stack<Node *>s;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        if(dir==0)//R to L
        {
            while(size--)
            {
            Node *t=q.front();
            q.pop();
            ans.push_back(t->data);
            if(t->right)
                s.push(t->right);
            if(t->left)
                s.push(t->left);
            }
            dir=1;
        }
        else//L to R
        {
            while(size--)
            {
            Node *t=q.front();
            q.pop();
            ans.push_back(t->data);
            if(t->left)
                s.push(t->left);
            if(t->right)
                s.push(t->right);
            }
            dir=0;
        }
        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }
    return ans;
}
