class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        
        int res=-1, fresh=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
            
        while(!q.empty()){
            
            res++;
            
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                auto p=q.front();
                
                q.pop();
                
                int x=p.first, y=p.second;
                                                
                if(x-1>-1&&grid[x-1][y]==1){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                    fresh--;
                }
                
                if(x+1<grid.size()&&grid[x+1][y]==1){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                    fresh--;
                }
                
                if(y-1>-1&&grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                    fresh--;
                }
                
                if(y+1<grid[0].size()&&grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                    fresh--;
                }
            }   
        }
            
        if(fresh)
            return -1;
            
        return max(0,res);
    }
};