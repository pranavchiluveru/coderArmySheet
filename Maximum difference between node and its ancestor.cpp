//Function to return the maximum difference between any node and its ancestor.
void diffAncNode(Node *root,int anc,int &maxi)
{
    if(!root)
    return;
    maxi=max(maxi,anc-root->data);
    anc=max(anc,root->data);
    diffAncNode(root->left,anc,maxi);
    diffAncNode(root->right,anc,maxi);
}
int maxDiff(Node* root)
{
    // Your code here 
    int anc=root->data;
    int maxi=INT_MIN;
    diffAncNode(root->left,anc,maxi);
    diffAncNode(root->right,anc,maxi);
    return maxi;
}
