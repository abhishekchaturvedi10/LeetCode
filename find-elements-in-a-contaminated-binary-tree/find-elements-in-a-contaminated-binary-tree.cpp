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
class FindElements {
public:
    map<int,int> m;
    void helper(TreeNode* root, int val) {
        if(!root) return;
        root->val=val;
        m[val]++;
        helper(root->left, 2*val+1);
        helper(root->right, 2*val+2);
    }
    FindElements(TreeNode* root) {
        root->val=0; m[0]++;
        helper(root->left, 1); helper(root->right, 2);
    }
    
    bool find(int target) {
        if(m[target]) return true;
        return false;
    }
};
​
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
