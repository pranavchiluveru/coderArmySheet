class Solution
{
public:
    void find(Node *root,vector<Node *> &ans,int level)
    {
        if(!root)return;
        if(level%2==1)
            ans.push_back(root);
        find(root->left,ans,level+1);
        find(root->right,ans,level+1);
    }
    vector<Node *> nodesAtOddLevels(Node *root)
    {
        //code here
        vector<Node *> ans;
        int level=1;
        find(root,ans,level);
        return ans;
    }
};
