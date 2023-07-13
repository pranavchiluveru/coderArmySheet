class Solution {
  public:

    void find(Node* root,Node* &prev,Node* &first,Node* &second)
    {
        /*
        //inorder traversal TC=O(n) SC=O(n)
        if(!root)return;
        //left side
        find(root->left,prev,first,second);
        //do something about root
        if(prev)
        {
            if(prev->data>root->data)//value decrease
            {
                if(!first&&!second)//1st time decrease
                {
                    first=prev;
                    second=root;
                }
                else//2nd time decrease
                {
                    second=root;
                }
            }
        }
        prev=root;
        //right side
        find(root->right,prev,first,second);
        
        */
        
        //inorder Morris Traversal TC=O(n),SC=(n)
        while(root)
        {
        //left exists
        if(root->left)
        {
            Node* curr=root->left;
            while(curr->right&&curr->right!=root)
                curr=curr->right;
            if(!curr->right)
            {
                curr->right=root;
                root=root->left;
            }
            else
            {
                curr->right=NULL;
                //print root//added code to Morris Traversal
                if(prev)
                {
                    if(prev->data>root->data)
                    {
                        if(!first&&!second)
                        {
                            first=prev;
                            second=root;
                        }
                        else
                            second=root;
                    }
                }
                prev=root;
                
                root=root->right;
            }
        }
        //left doesnt exists
        else
        {
            //print root//added code to Morris Traversal
            if(prev)
                {
                    if(prev->data>root->data)
                    {
                        if(!first&&!second)
                        {
                            first=prev;
                            second=root;
                        }
                        else
                            second=root;
                    }
                }
            prev=root;
            
            root=root->right;
            
        }
        }
        
        
    }
    struct Node *correctBST(struct Node *root) {
        // code here
        Node *prev=NULL,*first=NULL,*second=NULL;
        find(root,prev,first,second);
        swap(first->data,second->data);
        return root;
    }
};
