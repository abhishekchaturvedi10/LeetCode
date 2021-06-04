class Solution {
public:
    
    int maxDistance(vector<vector<int>>& g) {
        
        queue<vector<int>> q;
    
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    q.push({i,j,0});
                }
                else{
                    g[i][j]=-1;
                }
            }
        }
        
        // for(int i=0;i<g.size();i++){
        //     for(int j=0;j<g[0].size();j++){
        //         cout<<g[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        
        if(q.empty()||q.size()==g.size()*g[0].size())
            return -1;
        
        int res=0;
    
        while(!q.empty()){
            
            int len=q.size();
        
            while(len--){
            
                auto v=q.front();
            
                q.pop();
            
                int x=v[0], y=v[1], d=v[2];
                
                res=max(res,d);
                                            
                if(x>0&&g[x-1][y]==-1){
                    g[x-1][y]=d+1;
                    q.push({x-1,y,d+1});
                }
            
                if(y>0&&g[x][y-1]==-1){
                    g[x][y-1]=d+1;
                    q.push({x,y-1,d+1});
                }
            
                if(x<g.size()-1&&g[x+1][y]==-1){
                    g[x+1][y]=d+1;
                    q.push({x+1,y,d+1});
                }
            
                if(y<g[0].size()-1&&g[x][y+1]==-1){
                    g[x][y+1]=d+1;
                    q.push({x,y+1,d+1});
                }
            }
        }  
        
        // for(int i=0;i<g.size();i++){
        //     for(int j=0;j<g[0].size();j++){
        //         cout<<g[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        
        return res;
    }
};