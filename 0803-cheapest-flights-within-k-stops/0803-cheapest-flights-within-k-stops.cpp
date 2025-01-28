class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int source, int dst, int kk) {
                
        vector<vector<int>> dist(n + 1, vector<int>(n+1,1e8));
        
        for (int j = 0; j <= kk+1; j++) 
            dist[source][j] = 0;

        for (int k = 1; k <= kk+1; k++) {
            for (auto edge : edges) {
                int u = edge[0], v = edge[1], weight = edge[2];
                dist[v][k] = min({dist[v][k], dist[v][k - 1], dist[u][k - 1] + weight});
            }
        }
        
        return dist[dst][kk+1]==1e8?-1:dist[dst][kk+1];
    }
};