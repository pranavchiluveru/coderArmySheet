class Solution
{
    public:
    void find(Node *root, int &k,int &ans)
    {
        if(!root||k<0)return;
        find(root->right,k,ans);
        k--;
        if(k==0)
        {
            ans=root->data;
            return;
        }
        find(root->left,k,ans);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans=0;
        find(root,K,ans);
        return ans;
        
    }
};
