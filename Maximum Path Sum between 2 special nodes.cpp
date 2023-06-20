class Solution {
public:
    int sum(Node * root,int &s)
    {
       if(!root)return 0;
       if(!root->left&&!root->right)return root->data;
       int left=sum(root->left,s);
       int right=sum(root->right,s);
       if(root->left && root->right)
       {
            s=max(s,left+right+root->data);
            return root->data+max(left,right);
       }
       if(root->left)
       return root->data+left;
       if(root->right)
       return root->data+right;
    }
    int maxPathSum(Node* root)
    {
        // code here
        int s=INT_MIN;
        int k=sum(root,s);
        if(root->left&&root->right)
        return s;
        else
        return max(k,s);
    }
};
