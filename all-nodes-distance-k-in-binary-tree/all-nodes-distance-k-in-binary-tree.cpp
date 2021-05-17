/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> path;
    
    vector<int> res;
    
    bool getPath(TreeNode* root, int target){
        
        if(!root)
            return 0;
        
        if(root->val==target){
            path.push_back(root);
            return 1;
        }
        
        bool l=getPath(root->left, target);
        
        if(l){
            path.push_back(root);
            return true;
        }
        
        bool r=getPath(root->right, target);
        
        if(r){
            path.push_back(root);
            return true;
        }
        
        return false;
    }
    
    void KnodesDown(TreeNode* root, int k, TreeNode* block){
        
        if(k<0||!root||root==block){
            return;
        }
        
        if(k==0){
            res.push_back(root->val);
            return;
        }
        
        KnodesDown(root->left, k-1, block);
        KnodesDown(root->right, k-1, block);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        getPath(root, target->val);
        
        for(int i=0;i<path.size();i++){
            KnodesDown(path[i], k-i, i==0?NULL:path[i-1]);
        }
        
        return res;
    }
};