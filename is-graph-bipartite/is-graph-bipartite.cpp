class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        
        int n=g.size();
        
        vector<int> color(n,-1);
        
        for(int ii=0;ii<n;ii++){
            
            if(color[ii]!=-1)
                continue;
        
            queue<int> q;
            
            q.push(ii);
        
            color[ii]=0;
        
            while(!q.empty()){
            
                int sz=q.size();
                
                for(int k=0;k<sz;k++){
                
                    int i=q.front();
            
                    q.pop();
            
                    for(int j:g[i]){
                    
                        if(color[j]==color[i])
                            return 0;
                    
                        if(color[j]==-1)
                            color[j]=color[i]==0?1:0, q.push(j);
                    }
                }
            }
        }
        
        return 1; 
    }
};