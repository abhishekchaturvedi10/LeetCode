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
    
    unordered_map<string, int> map;
        
    vector<TreeNode*> ans;
    
    string solve(TreeNode* root){
        
        if(root == NULL)
            return "N";

        string temp = to_string(root->val) + "&"+ solve(root->left) +"&"+ solve(root->right);
        
        map[temp]++;
        
        if(map[temp] == 2)
            ans.push_back(root);
        
        return temp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        solve(root);

        return ans;
    }
};