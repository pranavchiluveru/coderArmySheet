void find(Node* root, int x,bool &ans)
{
    if(!root||ans)return;
    if(root->data==x)
    {
        ans=1;
        return;
    }
    else if(root->data>x)
        find(root->left,x,ans);
    else
        find(root->right,x,ans);
    
}
bool search(Node* root, int x) {
    // Your code here
    bool ans=0;
    find(root,x,ans);
    return ans;
}
