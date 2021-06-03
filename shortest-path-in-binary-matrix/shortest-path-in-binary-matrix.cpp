class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        
        if(g[g.size()-1][g.size()-1]||g[0][0])
            return -1;
        
        queue<vector<int>> q;
        
        q.push({0,0});
        
        int steps=0;
        
        while(!q.empty()){
            
            steps++;
            
            int len=q.size();
            
            while(len--){
                
                auto v=q.front();
                
                q.pop();
                
                if(v[0]==g.size()-1&&v[1]==g.size()-1)
                    return steps;
                                
                if(v[0]>=0&&v[0]<g.size()&&v[1]>=0&&v[1]<g.size()&&!g[v[0]][v[1]]){
                    
                    g[v[0]][v[1]]=1;
                    
                    for(int i=-1;i<2;i++)
                        for(int j=-1;j<2;j++){
                            
                            if(i==0&&j==0)
                                continue;
                            
                                q.push({v[0]+i,v[1]+j});
                        }
                }
            }
        }
        
        return -1;
    }
};