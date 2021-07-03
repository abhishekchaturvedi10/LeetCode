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
    
    TreeNode* rec(vector<int>& nums, int s, int e){
        
        if(s>e)
            return NULL;
        
        TreeNode *root = new TreeNode(nums[(s+e)/2]);
        
        root->left = rec(nums, s, (s+e)/2-1);
        root->right = rec(nums, (s+e)/2+1, e);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(nums, 0, nums.size()-1);
    }
};