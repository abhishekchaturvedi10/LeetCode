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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(!postorder.size())
            return NULL;
        
        int ind;
        
        for(int i=0;i<inorder.size();i++)
            if(inorder[i]==postorder[postorder.size()-1])
                ind=i;
        
        TreeNode *root=new TreeNode(postorder[postorder.size()-1]);
        
        vector<int> v1(postorder.begin(),postorder.begin()+ind), v2(inorder.begin(),inorder.begin()+ind), v3(postorder.begin()+ind,postorder.begin()+postorder.size()-1), v4(inorder.begin()+ind+1,inorder.end());
        
        root->left=buildTree(v2, v1);
        root->right=buildTree(v4, v3);
                              
        return root;
    }
};