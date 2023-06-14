class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root,int &ans)
    {
        if(!root)return 0;
        int lsth=height(root->left,ans);
        int rsth=height(root->right,ans);
        ans=max(ans,1+lsth+rsth);
        return 1+max(lsth,rsth);
    }
    int diameter(Node* root) {
        // Your code here
        int ans=0;
        height(root,ans);
        return ans;
        
    }
};
