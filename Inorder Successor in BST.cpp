    void successor(Node* root,Node *x,Node* &ans,bool &found)
    {
        if(!root||ans)return;
        successor(root->left,x,ans,found);
        if(found)
        {
            ans=root;
            return;
        }
        if(root==x)
            found=1;
        successor(root->right,x,ans,found);
        
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *ans=NULL;
        bool found=0;
        successor(root,x,ans,found);
        return ans;
    }
