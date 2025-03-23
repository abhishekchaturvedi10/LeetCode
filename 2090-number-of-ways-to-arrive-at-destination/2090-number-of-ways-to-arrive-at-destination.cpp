class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,1e12);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        vector<vector<vector<long long>>> g(n);
        for(auto v:roads) {
            g[v[0]].push_back({v[1],v[2]});
            g[v[1]].push_back({v[0],v[2]});
        }
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        long long mod= 1e9+7;
        pq.push({0,0});
        while(!pq.empty()) {
            long long node = pq.top()[1];
            long long distt = pq.top()[0];
            pq.pop();
            for(auto x:g[node]) {
                long long adjNode = x[0];
                long long weight =  x[1];         
                if(dist[adjNode]>weight+distt) {
                    dist[adjNode]=weight+distt;
                    ways[adjNode]=ways[node]%mod;
                    pq.push({dist[adjNode],adjNode});
                } else if(dist[x[0]]==x[1]+distt) {
                    ways[x[0]]=(ways[x[0]]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};