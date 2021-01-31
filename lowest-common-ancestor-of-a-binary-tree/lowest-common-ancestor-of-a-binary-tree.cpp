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
    map<TreeNode*, TreeNode*> par; 
    map<TreeNode *, int> level;
    void dfs(TreeNode *cur, TreeNode *parent){
        if(!cur)
            return;
        par[cur]=parent;
        level[cur]=level[parent]+1;
        dfs(cur->left, cur);
        dfs(cur->right, cur);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        level[root]=1;
        dfs(root->left, root);
        dfs(root->right, root);
        while(level[p]>level[q]){
            level[p]--;
            p=par[p];
        }
        while(level[q]>level[p]){
            level[q]--;
            q=par[q];
        }
        while(p!=q){
            p=par[p];
            q=par[q];
        }
        return p;
    }
};