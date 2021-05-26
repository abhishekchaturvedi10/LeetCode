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
    
    map<TreeNode*,int> dp_Robbed, dp_notRobbed;
    
    int dfs(TreeNode* root, int lastRobbed){
        
        if(!root)
            return 0;
        
        if(lastRobbed&&dp_notRobbed.find(root)!=dp_notRobbed.end())
            return dp_notRobbed[root];
        
        if(!lastRobbed&&dp_Robbed.find(root)!=dp_Robbed.end())
            return dp_Robbed[root];
        
        if(lastRobbed){
            dp_notRobbed[root]=dfs(root->left, 0)+dfs(root->right,0);
            return dp_notRobbed[root];
        }
        else{
            dp_Robbed[root]=max(dfs(root->left, 0)+dfs(root->right,0), root->val+dfs(root->left, 1)+dfs(root->right,1));
            return dp_Robbed[root];
        }
    }
    
    int rob(TreeNode* root) {
                
        return max(dfs(root,0),dfs(root,1));
    }
};