/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution{
public:

    //Function that constructs BST from its preorder traversal.
    Node* find(int pre[],int min,int max,int &index,int size)
    {
        if(index>=size||pre[index]<min||pre[index]>max)
            return NULL;
        Node * root=newNode(pre[index]);
        index++;
        root->left=find(pre,min,root->data,index,size);
        root->right=find(pre,root->data,max,index,size);
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        //code here
        int min=INT_MIN,max=INT_MAX,index=0;
        return find(pre,min,max,index,size);
    }
};
