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
    int res;
    int rec(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = rec(root->left);
        int r = rec(root->right);
        res=max({res,l+r+root->val,l+root->val,r+root->val,root->val});
        return max({root->val+l, root->val+r, root->val});
    }
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        rec(root);
        return res;
    }
};