int minValue(Node* root) {
    // Code here
    if(!root)return -1;
    if(root->left)
    {
        minValue(root->left);
    }
    else
        return root->data;
}
