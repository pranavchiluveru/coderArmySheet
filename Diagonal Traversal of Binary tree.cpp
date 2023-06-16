void preorder(Node *root,vector<vector<int>> &ans,int left)
{
    if(!root)return;
    if (left >= ans.size()) {
        ans.resize(left + 1);
    }
    ans[left].push_back(root->data);
    preorder(root->left,ans,left+1);
    preorder(root->right,ans,left);
}

vector<int> diagonal(Node *root)
{
   // your code here
   vector<vector<int>>ans;
   vector<int> a;
   if(!root)return a;
   int left=0;//Imp variable :whenever we go left we incremnet this and add ele which has same left value to vector
   preorder(root,ans,left);
   for(int i=0;i<ans.size();i++)
   {
       for(int j=0;j<ans[i].size();j++)
       {
           a.push_back(ans[i][j]);
       }
   }
   return a;
}
