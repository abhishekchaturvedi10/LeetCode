class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        
        auto [left_rob, left_not_rob] = dfs(root->left);
        auto [right_rob, right_not_rob] = dfs(root->right);
        
        int rob_current = root->val + left_not_rob + right_not_rob;
        int not_rob_current = max(left_rob, left_not_rob) + max(right_rob, right_not_rob);
        
        return {rob_current, not_rob_current};
    }
    
    int rob(TreeNode* root) {
        auto [rob, not_rob] = dfs(root);
        return max(rob, not_rob);
    }
};