class Solution {
  public:
    void findTarget(Node* root,Node* &temp,int target)
    {
        if(!root)return;
        if(root->data==target)
        temp=root;
        findTarget(root->left,temp,target);
        findTarget(root->right,temp,target);
    }
    int heightTarget(Node * root)
    {
        if(!root)return 0;
        return 1+max(heightTarget(root->left),heightTarget(root->right));
    }
    int burnTree(Node* root,int target,int &time)
    {
        if(!root)return 0;
        if(root->data==target)return -1;
        int left=burnTree(root->left,target,time);
        int right=burnTree(root->right,target,time);
        if(left<0)
        {
            time=max(time,abs(left)+right);
            return left-1;
        }
        else if(right<0)
        {
            time=max(time,abs(right)+left);
            return right-1;
        }
        else{
            return 1+max(left,right);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        Node * temp;
        findTarget(root,temp,target);
        int h=heightTarget(temp)-1;//excluding temp 
        int time=0;
        burnTree(root,target,time);
        return max(time,h);
    }
};
