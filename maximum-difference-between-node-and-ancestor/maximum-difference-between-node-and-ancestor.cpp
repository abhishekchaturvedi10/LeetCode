/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root, int maxi, int mini) {
        if(!root) return;
        if(root->val>maxi) maxi=root->val;
        if(root->val<mini) mini=root->val;
        ans=max(ans, maxi-mini);
        dfs(root->left, maxi, mini); dfs(root->right,maxi, mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, -1, 100001);
        return ans;
    }
};
