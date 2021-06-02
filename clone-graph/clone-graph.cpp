/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*, Node*> m;
    
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return NULL;
        
        if(m.find(node)!=m.end())
            return m[node];
    
        Node* copy=new Node(node->val);
        
        m[node]=copy;
        
        for(auto n:node->neighbors)
            copy->neighbors.push_back(cloneGraph(n));
        
        return m[node];
    }
};