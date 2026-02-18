class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<vector<int>>> graph(n+1);

        for(vector<int>& t:times) {
            int u=t[0], v=t[1], w=t[2];
            graph[u].push_back({v,w});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,k});

        vector<int> distance(n+1, INT_MAX);
        distance[k]=0;

        while(pq.size()) {
            vector<int> topElement = pq.top();
            pq.pop();
            int u = topElement[1], dist = topElement[0];
            if(dist>distance[u]) {
                continue;
            }
            auto neighbors = graph[u];
            for(auto& neighbor: neighbors) {
                int v = neighbor[0], weight = neighbor[1];
                int curDist = dist + weight;
                if(distance[v] > curDist) {
                    pq.push({curDist, v});
                    distance[v] = curDist;
                }
            }
        }

        int maxTime = -1;
        for(int i=1;i<=n;i++) {
            maxTime = max(maxTime,distance[i]);
        }

        return maxTime == INT_MAX ? -1:maxTime;
    }
};