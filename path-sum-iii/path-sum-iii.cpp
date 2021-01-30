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
    map<int, int> seenSum;
    int ans=0;
    void dfs(TreeNode *root, int cursum, int sum){
        if(!root)
            return;
        cursum+=root->val;
        ans+=seenSum[cursum-sum];
        seenSum[cursum]++;
        dfs(root->left, cursum, sum);
        dfs(root->right, cursum, sum);
        seenSum[cursum]--;
    }
    int pathSum(TreeNode* root, int sum) {
        seenSum[0]=1;
        dfs(root, 0, sum);
        return ans;
    }
};