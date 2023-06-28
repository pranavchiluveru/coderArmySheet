void inorder(Node* root,int &k,int &ans)
{
    if(!root||k==0)return;
    inorder(root->left,k,ans);
    if(k>0){
        ans+=root->data;
        k--;
    }
    inorder(root->right,k,ans);
}
int sum(Node* root, int k) 
{ 
  
    // Your code here
    int ans=0;
    inorder(root,k,ans);
    return ans;
    
    
} 
