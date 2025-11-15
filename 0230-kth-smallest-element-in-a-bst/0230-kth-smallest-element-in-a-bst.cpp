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
    void rec(TreeNode* root, int& k) {
        if(!root || k<=0) {
            return;
        }
        rec(root->left,k);
        --k;
        if(k==0) {
            res=root->val;
            return;
        }
        rec(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        res=-1;
        rec(root,k);
        return res;
    }
};