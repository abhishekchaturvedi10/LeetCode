class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> g(n+1);
        
        for(auto time:times)
            g[time[0]].push_back({time[1],time[2]});
                
        queue<pair<int,int>> q;
        
        q.push({k,0});
        
        vector<int> delay(n+1,INT_MAX);
        
        delay[k]=0;
                
        while(!q.empty()){
                        
            int sz=q.size();
            
            while(sz--){
                
                auto u=q.front();
                
                q.pop();
                                
                for(auto j:g[u.first]){
                    if(delay[j.first]>j.second+delay[u.first]){
                        q.push({j.first,j.second+delay[u.first]});
                        delay[j.first]=j.second+delay[u.first];
                    }
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