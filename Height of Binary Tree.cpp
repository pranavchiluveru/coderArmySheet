struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
        if(!root)
        return 0;
        if(root->left==NULL && root->right==NULL)
        return 1;
        return 1+max(height(root->left),height(root->right));
    }
};
