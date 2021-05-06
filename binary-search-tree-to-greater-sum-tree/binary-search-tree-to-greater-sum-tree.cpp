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
    
    int x=0;
    
    void dfs(TreeNode *root){
        
        if(!root)
            return;
            
        dfs(root->right);
        
        x += root->val;
        
        root->val = x;
        
        dfs(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
                        
        if(!root)
            return root;
        
        dfs(root);
        
        return root;
    }
};