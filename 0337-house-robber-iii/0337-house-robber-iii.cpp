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
    int dfs(TreeNode* root, bool isParentBroken, map<pair<TreeNode*,bool>,int>& dp) {
        if(!root) {
            return 0;
        } 
        if(dp.find({root,isParentBroken})!=dp.end()) {
            return dp[{root,isParentBroken}];
        }
        if(isParentBroken) {
            return dp[{root,isParentBroken}]=dfs(root->left,false,dp)+dfs(root->right,false,dp);
        } else {
            return dp[{root,isParentBroken}]=max(dfs(root->left,false,dp)+dfs(root->right,false,dp),root->val+dfs(root->left,true,dp)+dfs(root->right,true,dp));
        }
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int> dp;
        return max(dfs(root,false,dp),dfs(root,true,dp));
    }
};