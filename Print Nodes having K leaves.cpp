class Solution{
  public:
    
    int countleaves(Node *root,int k,vector<int> &ans)
    {
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return 1;
        int leftleaves=countleaves(root->left,k,ans);
        int rightleaves=countleaves(root->right,k,ans);
        if(leftleaves+rightleaves==k)
            ans.push_back(root->data);
        return leftleaves+rightleaves;
    }
  /*You are required to complete below method */
    vector<int> btWithKleaves(Node *ptr, int k)
    { 
        //your code here.
        vector<int> ans;
        countleaves(ptr,k,ans);
        if(ans.empty())
            ans.push_back(-1);
        return ans;
    }

};
