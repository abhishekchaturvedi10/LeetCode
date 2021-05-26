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
    
    TreeNode* dfs(TreeNode *root, int key){
                
        if(!root)
            return NULL;
        
        if(root->val==key){
            
            if(!root->left&&!root->right)
                return NULL;
            
            else if(!root->right)
                return root->left;
            
            else if(!root->left)
                return root->right;
            
            else{
                
                TreeNode* dummy=new TreeNode(0);
                            
                TreeNode *tempright=root->right;
                
                root=root->left;
                
                dummy->right=root;
                
                while(root->right)
                    root=root->right;
                
                root->right=tempright;
                
                return dummy->right;
            }
        }
        
        root->left=dfs(root->left,key);
        root->right=dfs(root->right,key);
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return dfs(root,key);
    }
};