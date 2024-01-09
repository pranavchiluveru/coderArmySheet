/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void order(TreeNode* root,vector<int> &n)
    {
        if(!root)return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            n.push_back(root->val);
            return ;
        }
        order(root->left,n);
        order(root->right,n);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> n1;
        vector<int> n2;
        order(root1,n1);
        order(root2,n2);
        return n1==n2;
    }
};
