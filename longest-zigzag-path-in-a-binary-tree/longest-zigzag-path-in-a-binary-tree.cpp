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
        
    int dfs(TreeNode* root, int dir, int d){
        
        if(!root)
            return d;
        
        if(!dir)
            return max(dfs(root->left,0,0), dfs(root->right,1,d+1));
        else
            return max(dfs(root->right,1,0), dfs(root->left,0,d+1));
    }
    
    int longestZigZag(TreeNode* root) {
        
        return max(dfs(root,0,-1), dfs(root,1,-1));
    }
};