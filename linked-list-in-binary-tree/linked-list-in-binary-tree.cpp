/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    vector<vector<int>> paths;
    
    void dfs(TreeNode *root, vector<int> path){
        
        if(!root)
            return;
        
        path.push_back(root->val);
        
        if(!root->left&&!root->right){
            paths.push_back(path);
            return;
        }
        
        dfs(root->left, path);
        dfs(root->right, path);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        dfs(root, vector<int>());
        
        vector<int> list;
        
        while(head){
            list.push_back(head->val);
            head=head->next;
        }
        
        for(auto path:paths){
            
            if(path.size()<list.size())
                continue;
            
            int i=0;
            
            while(i<path.size()){
                
                if(i+list.size()>path.size())
                    break;
                
                vector<int> temp(path.begin()+i,path.begin()+i+list.size());
                
                if(temp==list)
                    return true;
                
                i++;
            }
        }
        
        return false;
    }
};