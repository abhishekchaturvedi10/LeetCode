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
    map<TreeNode*, TreeNode*> par;
    vector<vector<TreeNode*>> depth;
    int dmax;
    void dfs(TreeNode* prev,TreeNode* root, int d){
        if(!root){
            dmax=max(dmax, d-1);
            return;
        }
        depth[d].push_back(root);
        par[root]=prev;
        dfs(root, root->left, d+1);
        dfs(root, root->right, d+1);
    }
    TreeNode* LCA(TreeNode* x, TreeNode* y){
        while(x!=y){
            x=par[x];
            y=par[y];
        }
        return x;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dmax=-1;
        depth.resize(501);
        dfs(root, root, 0);
        if(depth[dmax].size()==1)
            return depth[dmax][0];
        return LCA(depth[dmax][0], depth[dmax][depth[dmax].size()-1]);
    }
};