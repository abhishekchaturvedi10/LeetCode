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
    
    map<pair<int,int>,multiset<int>> m;
    
    void dfs(TreeNode* root, int x, int y){
        
        if(!root)
            return;
        
        dfs(root->left, x-1, y+1);
        
        dfs(root->right, x+1, y+1);
        
        m[{x,y}].insert(root->val);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root, 0, 0);
        
        vector<vector<int>> res;
        
        // for(auto& i:m)
        //     sort(i.second.begin(),i.second.end());
        
        map<int,vector<int>> mm;
        
        for(auto i:m)
            for(int j:i.second)
                mm[i.first.first].push_back(j);
        
        for(auto i:mm)
            res.push_back(i.second);
        
        return res;
    }
};