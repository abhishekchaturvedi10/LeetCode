class Solution {
public:
    
    void dfs(int x, int y, vector<vector<int>>& g, int color){
        
        if(x<0||y<0||x>=g.size()||y>=g[0].size()||g[x][y]!=1)
            return;
        
        g[x][y]=color;
        
        dfs(x-1,y,g,color);
        dfs(x+1,y,g,color);
        dfs(x,y-1,g,color);
        dfs(x,y+1,g,color);
    }
    
    int shortestBridge(vector<vector<int>>& g) {
        
        int color=-1;
        
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    dfs(i,j,g,color);
                    color--;
                }
            }
        }
            
        queue<vector<int>> q;
        
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==-1){
                    q.push({i,j,0});
                }
            }
        }
        
        int res=INT_MAX;
        
        while(!q.empty()){
            
            int len=q.size();
            
            while(len--){
                
                auto v=q.front();
                
                q.pop();
                
                int x=v[0], y=v[1], d=v[2];
                
                if(g[x][y]==-2)
                    return d-1;
                
                if(x>0&&(g[x-1][y]==0||g[x-1][y]==-2)){
                    
                    if(g[x-1][y]==-2)
                        res=min(d,res);
                    
                    if(g[x-1][y]==0)
                        g[x-1][y]=d+1, q.push({x-1,y,d+1});
                }
                
                if(y>0&&(g[x][y-1]==0||g[x][y-1]==-2)){
                    
                    if(g[x][y-1]==-2)
                        res=min(d,res);
                    
                    if(g[x][y-1]==0)
                        g[x][y-1]=d+1, q.push({x,y-1,d+1});
                }
                
                if(x<g.size()-1&&(g[x+1][y]==0||g[x+1][y]==-2)){
                    
                    if(g[x+1][y]==-2)
                        res=min(d,res);
                    
                    if(g[x+1][y]==0)
                        g[x+1][y]=d+1, q.push({x+1,y,d+1});
                }
                
                if(y<g[0].size()-1&&(g[x][y+1]==0||g[x][y+1]==-2)){
                    
                    if(g[x][y+1]==-2)
                        res=min(d,res);
                    
                    if(g[x][y+1]==0)
                        g[x][y+1]=d+1, q.push({x,y+1,d+1});
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