/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,long> m, q;
    void helper(TreeNode* root, int lvl) {
        if(!root) return;
        m[lvl]+=root->val; q[lvl]++;
        cout<<root->val<<" "<<lvl<<" : ";
        helper(root->left, lvl+1); 
        helper(root->right, lvl+1);
    }
    int maxLevelSum(TreeNode* root) {
        helper(root, 1);
        long ans = m[1]; int level=2, l=1;
        while(q[level]) {
            if(m[level]>ans) {
                ans=m[level]; l=level;
            }
            level++;
        }
        return l;
    }
};
