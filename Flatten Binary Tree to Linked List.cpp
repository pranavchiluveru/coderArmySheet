class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        //using PreOrder Morris Traversal with changes TC=O(N) SC=O(1)
        while(root)
        {
            if(root->left)
            {
                Node* curr=root->left;
                while(curr->right)
                    curr=curr->right;
                curr->right=root->right;
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
            else
            {
                root=root->right;
            }
        }
    }
};
