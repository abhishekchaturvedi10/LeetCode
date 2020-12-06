class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<vector<int>>& graph,vector<int>& cur, int i) {
        
        cur.push_back(i);
        
        if(i==graph.size()-1) {
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        
        if(graph[i].size()==0) {
            cur.pop_back();
            return;
        }
        
        for(int j=0;j<graph[i].size();j++) {
            helper(graph, cur, graph[i][j]);
        }
        
        cur.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur;
        helper(graph, cur, 0);
        return ans;
    }
};
