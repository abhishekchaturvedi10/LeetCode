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
    string res;

    void rec(TreeNode* root) {
        if(!root) {
            res+="()";
            return;
        }
        
        res+='(';
        res+=to_string(root->val);
        if(!root->left&&!root->right) {
            res+=')';
            return;
        }
        rec(root->left);
        if(root->right) {
            rec(root->right);
        }
        res+=')';
    }

    string tree2str(TreeNode* root) {
        rec(root);
        return res.substr(1,res.size()-2);
    }
};