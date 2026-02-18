class Solution {
public:

    vector<vector<int>> graph;
    vector<int> vis;
    vector<int> inStack;
    vector<int> courseOrder;

    bool topologySort(int u) {

        vis[u]=1;
        inStack[u]=1;

        for(int& v:graph[u]) {
            if((!vis[v] && topologySort(v)) || inStack[v]) {
                return true;
            }
        }

        inStack[u]=0;
        courseOrder.push_back(u);

        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        graph.resize(n);
        vis.resize(n);
        inStack.resize(n);

        for(vector<int>& prerequisite: prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }

        for(int i=0;i<n;i++) {
            if(!vis[i] && topologySort(i)) {
                return {};
            }
        }

        return courseOrder;
    }
};