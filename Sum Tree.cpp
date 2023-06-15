class Solution
{
    public:
    int sum(Node *root,bool &ans)
    {
        if(!root)
        return 0;
        if(!root->left &&!root->right)
        return root->data;
        int lsum=sum(root->left,ans);
        int rsum=sum(root->right,ans);
        if(lsum+rsum!=root->data)ans=0;
        return lsum+rsum+root->data;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         bool ans=1;
         sum(root,ans);
         return ans;
    }
};
