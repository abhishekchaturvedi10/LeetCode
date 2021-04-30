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
    int dfs(TreeNode* root){
        if(!root){
            return -1;
        }
        if(!root->left&&!root->right){
            return 0;
        }
        int l=0,r=0;
        if(root->left&&root->right){
            l=1+dfs(root->left);
            r=1+dfs(root->right);
            ans=max(ans,l+r);
            return max(l,r);
        }
        if(!root->left&&root->right){
            r=1+dfs(root->right);
            ans=max(ans,r);
            return r;
        }
        l=1+dfs(root->left);
        ans=max(ans,l);
        return l;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        ans=0;
        return max(ans, 2+dfs(root->left)+dfs(root->right));
    }
};