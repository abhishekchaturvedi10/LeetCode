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
    TreeNode* trim(TreeNode* root, int l, int r) {
        if(!root) {
            return NULL;
        }
        if(root->val<l) {
            return trim(root->right,l,r);
        }
        if(root->val>r) {
            return trim(root->left,l,r);
        }
        root->left = trim(root->left,l,r);
        root->right = trim(root->right,l,r);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int l, int r) {
        return trim(root,l,r);
    }
};