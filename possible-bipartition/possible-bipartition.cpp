class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> g(n+1);
        
        for(auto dislike:dislikes)
            g[dislike[0]].push_back(dislike[1]), g[dislike[1]].push_back(dislike[0]);
        
        vector<int> color(n+1,-1);
        
        for(int ii=1;ii<=n;ii++){
            
            if(color[ii]!=-1)
                continue;
        
            queue<int> q;
            
            q.push(ii);
        
            color[ii]=0;
        
            while(!q.empty()){
            
                int sz=q.size();
                
                while(sz--){
                
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