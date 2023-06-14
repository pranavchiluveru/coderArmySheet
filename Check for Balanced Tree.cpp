    int height(Node *root,bool &ans)
    {
        if(!root)return 0;
        int lsth=height(root->left,ans);
        int rsth=height(root->right,ans);
        if(abs(lsth-rsth)>1)
            ans=0;
        return 1+max(lsth,rsth);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        bool ans=1;
        height(root,ans);
        return ans;
    }
