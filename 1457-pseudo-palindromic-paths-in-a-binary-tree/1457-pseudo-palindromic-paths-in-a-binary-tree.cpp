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

    int res=0;

    void dfs(map<int,int>& freq, TreeNode* root, int oddFreqCount) {
        if(!root) {
            return;
        }
        freq[root->val]++;
        if(freq[root->val]&1) {
            oddFreqCount++;
        } else {
            oddFreqCount--;
        }
        if(!root->left&&!root->right) {
            if(oddFreqCount<2) {
                res++;
            }
        }
        dfs(freq, root->left, oddFreqCount);
        dfs(freq, root->right, oddFreqCount);
        freq[root->val]--;
        if(freq[root->val]&1) {
            oddFreqCount++;
        } else {
            oddFreqCount--;
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        res=0;
        map<int,int> freq;
        dfs(freq,root,0);
        return res;
    }
};