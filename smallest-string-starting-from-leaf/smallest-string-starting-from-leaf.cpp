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
    
    vector<string> paths;
    
    static bool comp(string &a, string &b){
        int i=0;
        while(i<min(a.size(),b.size())){
            if(b[i]-'a'>a[i]-'a')
                return 1;
            else if(a[i]-'a'>b[i]-'a')
                return 0;
            else
                i++;
        }
        return (b.size()>a.size());
    } 
    
    void rec(TreeNode* root, string s){
        
        if(!root->left&&!root->right){
            paths.push_back(s+char('a'+root->val));
            return;
        }
                
        if(root->left)
            rec(root->left, s+char('a'+root->val));
        
        if(root->right)
            rec(root->right, s+char('a'+root->val));
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        rec(root, "");
        
        for(auto &i:paths)
            reverse(i.begin(),i.end());
            
        sort(paths.begin(),paths.end(),comp);
        
        return paths[0];
    }
};