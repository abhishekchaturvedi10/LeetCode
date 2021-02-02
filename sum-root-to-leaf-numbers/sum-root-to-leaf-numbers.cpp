/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void dfs(TreeNode *root, string cur){
        if(!root->left&&!root->right){
            char x=root->val+'0';
            ans+=stoi(cur+x);
            return;
        }
        char x=root->val+'0';
        if(root->left)
            dfs(root->left, cur+x);
        if(root->right)
            dfs(root->right, cur+x);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        ans=0;
        dfs(root, "");
        return ans;
    }
};