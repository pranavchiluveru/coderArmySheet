class Solution {
public:
    int freq[10];
    int count = 0;
    void findallpaths(TreeNode* root) {
        if(!root)return;
        freq[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            if (check()) {
                count++;
            }
        }
        else{
            findallpaths(root->left);
            findallpaths(root->right);
        }
        freq[root->val]--;
    }

    bool check() {
        int oddCount = 0;
        for (auto it : freq) {
            if (it % 2 != 0) {
                oddCount++;
            }
        }

        return oddCount <= 1;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        findallpaths(root);
        return count;
    }
};
