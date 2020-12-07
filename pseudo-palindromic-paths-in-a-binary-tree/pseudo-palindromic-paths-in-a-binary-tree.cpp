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
    int ans=0;
    void dfs(TreeNode *root, vector<int> cur) {
        cur.push_back(root->val);
        if(!root->left&&!root->right) {
            vector<int> occ(10);
            for(int j=0;j<cur.size();j++) {
                occ[cur[j]]++;
            }
            int f=0;
            if(cur.size()%2==0) {
                for(int j=1;j<10;j++) {
                    if(occ[j]%2==1) f++;
                }
                if(!f) ans++;
            }
            else{
                for(int j=1;j<10;j++) {
                    if(occ[j]%2==1) f++;
                }
                if(f==1) ans++;
            }
            return;
        }
        if(root->left) dfs(root->left, cur); 
        if(root->right) dfs(root->right, cur);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return ans;
        vector<int> cur;
        dfs(root, cur);
        return ans;
    }
};
