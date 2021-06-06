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

private:
    
    vector<TreeNode*> rec(int l, int r){
        
        if(l>r)
            return {NULL};
        
        vector<TreeNode*> v;
                
        for(int i=l;i<=r;i++){
            
            auto vl=rec(l,i-1);
            auto vr=rec(i+1,r);
                        
            for(auto r:vl){
                
                for(auto rr:vr){
                    
                    TreeNode* root=new TreeNode(i);
                    
                    root->left=r;
                    root->right=rr;
                                            
                    v.push_back(root);
                }
            }
        }
        
        return v;
    }
    
public:
    
    vector<TreeNode*> generateTrees(int n) {
        
        return rec(1,n);
    }
};