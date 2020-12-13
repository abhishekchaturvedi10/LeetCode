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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) 
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n=q.size(),i=0,maxx=INT_MIN;
            cout<<n<<endl;
            while(i<n){
                i++;
                TreeNode* temp=q.front();
                maxx=max(maxx,temp->val);
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            ans.push_back(maxx);
        }
        return ans;
    }
};
