class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here
        //postorder: left right root==reverse(root right left)
        vector<int> ans;
        stack<Node *>s;
        s.push(root);
        while(!s.empty())
        {
            Node *temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            if(temp->left)
            s.push(temp->left);
            if(temp->right)
            s.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
