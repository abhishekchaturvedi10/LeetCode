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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
        if(!pre.size())
            return NULL;
        
        if(pre.size()==1){
            TreeNode *root=new TreeNode(pre[0]);
            return root;
        }
        
        int ind;
        
        for(int i=0;i<post.size();i++)
            if(post[i]==pre[1])
                ind=i;
        
        TreeNode *root=new TreeNode(post[post.size()-1]);
        
        vector<int> v1(post.begin(),post.begin()+ind+1), v2(pre.begin()+1,pre.begin()+ind+2), v3(post.begin()+ind+1,post.begin()+post.size()-1), v4(pre.begin()+ind+2,pre.end());
        
        root->left=constructFromPrePost(v2, v1);
        root->right=constructFromPrePost(v4, v3);
                              
        return root;
    }
};