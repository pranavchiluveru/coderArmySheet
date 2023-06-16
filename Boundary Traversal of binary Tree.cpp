class Solution {
public:
    void leftNodes(Node *root,vector<int> &ans)
    {
        if(!root)return;
        if(!root->left&&!root->right)return;
        ans.push_back(root->data);
        if(root->left)
            leftNodes(root->left,ans);
        else
            leftNodes(root->right,ans);
    }
    void leafs(Node *root,vector<int> &ans)
    {
        if(!root)return;
        if(!root->left&&!root->right)
            ans.push_back(root->data);
        leafs(root->left,ans);
        leafs(root->right,ans);
    }
    void rightNodes(Node *root,vector<int> &ans)
    {
        if(!root)return;
        if(!root->left&&!root->right)return;
        if(root->right)
            rightNodes(root->right,ans);
        else
            rightNodes(root->left,ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        leftNodes(root->left,ans);
        if(root->left ||root->right)
        leafs(root,ans);
        rightNodes(root->right,ans);
        return ans;
    }
};
