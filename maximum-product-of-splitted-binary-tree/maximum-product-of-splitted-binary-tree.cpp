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
    
    map<TreeNode*, long long int> dp;
    
    long long int res;
    
    int dfs(TreeNode* root){
        
        if(!root)
            return 0;
        
        return dp[root]=root->val+dfs(root->left)+dfs(root->right);
    }
    
    void dfs1(TreeNode* root, TreeNode* baap){
        
        if(!root)
            return;
        
        // cout<<root->val<<" "<<dp[root]<<'\n';
        
        res=max(res, (dp[baap]-dp[root])*dp[root]);
                
        dfs1(root->left,baap);
        dfs1(root->right,baap);
    }
    
    int maxProduct(TreeNode* root) {
        
        res=0;
        
        dfs(root);
        
        dfs1(root,root);
        
        return res%1000000007;
    }
};