
class Solution
{
    public:
    void find(Node* root,Node* &prev,int &ans)
    {
        //Morris inorder Traversal TC=O(N) SC=O(1)
        while(root)
        {
            if(root->left)//if left exists
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
                    //print root
                    if(prev)
                    {
                        ans=min(ans,abs(root->data-prev->data));
                    }
                    prev=root;
                    root=root->right;
                }
            }
            else//left doesnt exists
            {
                //print root
                if(prev)
                {
                    ans=min(ans,abs(root->data-prev->data));
                }
                prev=root;
                
                root=root->right;
            }
        }
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        int ans=INT_MAX;
        Node * prev;
        find(root,prev,ans);
        return ans;
    }
};
