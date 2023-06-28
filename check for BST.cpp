void bst(Node* root,bool &ans,int &prev)
    {
        if(!root||ans==0)return;
        bst(root->left,ans,prev);
        if(root->data>prev)
            prev=root->data;
        else
        {
            ans=0;
            return;
        }
        bst(root->right,ans,prev);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        bool ans=1;
        int prev=INT_MIN;
        bst(root,ans,prev);
        return ans;
    }
