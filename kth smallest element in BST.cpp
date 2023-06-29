class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void find(Node* root,int &k,int &ans)
    {
        if(!root||k<0)return;
        find(root->left,k,ans);
        k--;
        if(k==0)
        {
            ans=root->data;
            return;
        }
        find(root->right,k,ans);
    }
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int ans=-1;
        find(root,K,ans);
        return ans;
    }
};
