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
    vector<vector<int>> ans;
    void dfs(TreeNode *root, int target, vector<int> &vals, int cursum){
        if(!root)
            return;
        vals.push_back(root->val);
        if(!root->left&&!root->right)
            if(cursum+root->val==target)
                ans.push_back(vals);
        dfs(root->left, target, vals, cursum+root->val);
        dfs(root->right, target, vals, cursum+root->val);
        vals.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> a;
        dfs(root, targetSum, a, 0);
        return ans;
    }
};
