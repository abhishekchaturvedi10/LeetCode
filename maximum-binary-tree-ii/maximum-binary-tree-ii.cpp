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
    
    bool done;
    
    void helper(TreeNode* &root, int val){
        
        if(done)
            return;
        
        if(val>root->val){
            TreeNode *x=new TreeNode(val);
            x->left=root;
            root=x;
            done=1;
            return;
        }
                        
        if(!root->right){
            root->right=new TreeNode(val);
            done=true;
            return;
        }
        
        helper(root->right, val);
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

        done=false;
        
        helper(root, val);
        
        return root;
    }
};