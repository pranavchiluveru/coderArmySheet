struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    Node* BST(int arr[],int min,int max,int &index,int size)
    {
        if(index>=size||arr[index]>max||arr[index]<min)
            return NULL;
        Node* root=new Node(arr[index]);
        index++;
        root->left=BST(arr,min,root->data,index,size);
        root->right=BST(arr,root->data,max,index,size);
        return root;
    }
    int canRepresentBST(int arr[], int N) {
        // code here
        int min=INT_MIN,max=INT_MAX,index=0;
        Node* root=BST(arr,min,max,index,N);
        if(index==N&&root)
            return 1;
        else
            return 0;
    }
};
