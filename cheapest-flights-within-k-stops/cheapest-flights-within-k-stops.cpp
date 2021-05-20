class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int source, int dst, int kk) {
                
        vector<vector<int>> dist(n + 1, vector<int>(n+1,INT_MAX));
        
        for (int j = 0; j <= n; j++) 
            dist[source][j] = 0;

        for (int k = 1; k <= n; k++) {

            for (auto edge : edges) {

                int u = edge[0], v = edge[1], weight = edge[2];

                if (dist[u][k - 1] == INT_MAX) 
                    continue;
                
                dist[v][k] = min({dist[v][k], dist[v][k - 1], dist[u][k - 1] + weight});
            }
        }
        
        if(dist[dst][kk+1]==INT_MAX)
            return -1;
        
        return dist[dst][kk+1];
    }
};