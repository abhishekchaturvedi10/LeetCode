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
    
    vector<int> traversal;
    
    vector<TreeNode*> nodes;
    
    void inorder(TreeNode* root){
        
        if(!root)
            return;
        
        inorder(root->left);
        
        traversal.push_back(root->val);
        
        nodes.push_back(root);
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        
        vector<int> temp=traversal;
        
        sort(temp.begin(),temp.end());
        
        int x=-1,y;
                
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=traversal[i]){
                if(x==-1)
                    x=i;
                else
                    y=i;
            }
        }
        
        if(x!=-1){
            int temp=nodes[x]->val;
            nodes[x]->val=nodes[y]->val;
            nodes[y]->val=temp;
        }
    }
};