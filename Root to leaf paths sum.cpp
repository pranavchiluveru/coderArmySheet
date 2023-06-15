/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
void sum(Node *root,long long &ans,long long num)
{
    if(!root)
        return;
    num=num*10+root->data;
    if(!root->left&&!root->right)
        ans+=num;
    sum(root->left,ans,num);
    sum(root->right,ans,num);
}
long long treePathsSum(Node *root)
{
    //Your code here
    long long ans=0;
    long long num=0;
    sum(root,ans,num);
    return ans;
}
