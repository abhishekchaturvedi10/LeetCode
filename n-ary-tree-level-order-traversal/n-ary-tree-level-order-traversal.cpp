/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
​
    Node() {}
​
    Node(int _val) {
        val = _val;
    }
​
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
​
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q; q.push(root);
        while(q.size()>0){
            int n=q.size(), i=0;
            vector<int> cur;
            while(i<n){
                Node* temp=q.front(); q.pop();
                cur.push_back(temp->val);
                for(int j=0;j<temp->children.size();j++)
                    q.push(temp->children[j]);
                
                i++;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
