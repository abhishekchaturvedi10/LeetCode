class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        
        vector<vector<vector<int>>> graph(n, vector<vector<int>>());        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j)
                    graph[i].push_back({j, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
        
        vector<bool> inMst(n);
        
        vector<int> key(n, INT_MAX);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
                
        key[0]=0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            
            int u=pq.top()[1];
            
            pq.pop();
                        
            if(inMst[u])
                continue;
                        
            inMst[u]=1;
                                    
            for(auto i:graph[u]){
                
                if(!inMst[i[0]] && key[i[0]]>i[1]){
                    
                    key[i[0]]=i[1];
                    pq.push({key[i[0]], i[0]});
                }
            }
        }
        
        int res=0;
        
        for(int i:key)
            res+=i;
        
        return res;
    }
};