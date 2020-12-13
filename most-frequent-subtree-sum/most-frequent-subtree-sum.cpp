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
    map<int,int> m;
    int dfs(TreeNode* root, int sum){
        if(!root)
            return 0;
        sum+=root->val+dfs(root->left,sum)+dfs(root->right,sum);
        return sum;
    }
    void dfs1(TreeNode* root){
        if(!root)
            return;
        m[dfs(root,0)]++;
        dfs1(root->left);
        dfs1(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        dfs1(root);
        int maxfreq=0;
        for(auto i:m)
            maxfreq=max(maxfreq,i.second);
        for(auto i:m)
            if(i.second==maxfreq)
                ans.push_back(i.first);
        for(auto i:m)
            cout<<i.first<<" "<<i.second<<endl;    
        return ans;
    }
};
