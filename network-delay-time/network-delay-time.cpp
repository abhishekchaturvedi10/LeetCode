class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<vector<int>>> g(n+1);
        
        for(auto time:times)
            g[time[0]].push_back({time[1],time[2]});
                
        queue<int> q;
        
        q.push(k);
        
        vector<int> delay(n+1,INT_MAX);
        
        delay[k]=0;
                
        while(!q.empty()){
                        
            int u=q.front();
                
            q.pop();
                                
            for(auto j:g[u]){
                if(delay[j[0]]>j[1]+delay[u]){
                    q.push(j[0]);
                    delay[j[0]]=j[1]+delay[u];
                }
            }
        }
        
        int res=0;
        
        for(int i=1;i<=n;i++){
            if(delay[i]==INT_MAX)
                return -1;
            else
                res=max(res,delay[i]);
        }
        
        return res;
    }
};