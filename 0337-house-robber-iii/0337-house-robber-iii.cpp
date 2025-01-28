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
    map<pair<TreeNode*,bool>,int> dp;
    int dfs(TreeNode* root, bool isParentBroken) {
        if(!root) {
            return 0;
        } 
        if(dp.find({root,isParentBroken})!=dp.end()) {
            return dp[{root,isParentBroken}];
        }
        if(isParentBroken) {
            return dp[{root,isParentBroken}]=dfs(root->left,false)+dfs(root->right,false);
        } else {
            return dp[{root,isParentBroken}]=max(dfs(root->left,false)+dfs(root->right,false),root->val+dfs(root->left,true)+dfs(root->right,true));
        }
    }
    int rob(TreeNode* root) {
        return max(dfs(root,false),dfs(root,true));
    }
};