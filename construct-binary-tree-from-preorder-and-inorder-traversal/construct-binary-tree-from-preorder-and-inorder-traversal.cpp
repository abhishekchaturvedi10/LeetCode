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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(!preorder.size())
            return NULL;
        
        int ind;
        
        for(int i=0;i<inorder.size();i++)
            if(inorder[i]==preorder[0])
                ind=i;
        
        TreeNode *root=new TreeNode(preorder[0]);
        
        vector<int> v1(preorder.begin()+1,preorder.begin()+1+ind), v2(inorder.begin(),inorder.begin()+ind), v3(preorder.begin()+1+ind,preorder.end()), v4(inorder.begin()+ind+1,inorder.end());
        
        root->left=buildTree(v1, v2);
        root->right=buildTree(v3, v4);
                              
        return root;
    }
};