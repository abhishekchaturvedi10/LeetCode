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
    
    vector<string> paths;
    
    void rec(TreeNode* root, string s){
        
        if(!root->left&&!root->right){
            paths.push_back(s+char('a'+root->val));
            return;
        }
                
        if(root->left)
            rec(root->left, s+char('a'+root->val));
        
        if(root->right)
            rec(root->right, s+char('a'+root->val));
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        rec(root, "");
        
        for(auto &i:paths)
            reverse(i.begin(),i.end());
            
        sort(paths.begin(),paths.end());
        
        return paths[0];
    }
};