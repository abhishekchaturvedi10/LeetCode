class Solution {
public:
    
    void rec(int x, int y, vector<vector<int>>& g, vector<vector<int>>& g1){
        
        if(x<0||x==g.size()||y<0||y==g[0].size()||g[x][y]==0)
            return;
        
        g[x][y]=0;
        
        if(g1[x][y]==1)
            g1[x][y]=2;
        
        rec(x-1,y,g,g1);
        rec(x,y-1,g,g1);
        rec(x+1,y,g,g1);
        rec(x,y+1,g,g1);
    }
    
    void rec1(int x, int y, vector<vector<int>>& g){
        
        if(x<0||x==g.size()||y<0||y==g[0].size()||g[x][y]==0)
            return;
        
        g[x][y]=0;
        
        rec1(x-1,y,g);           
        rec1(x,y-1,g);
        rec1(x+1,y,g);
        rec1(x,y+1,g);
    }
    
    void rec2(int x, int y, vector<vector<int>>& g){
        
        if(x<0||x==g.size()||y<0||y==g[0].size()||g[x][y]!=2)
            return;
        
        g[x][y]=1;
        
        rec1(x-1,y,g);           
        rec1(x,y-1,g);
        rec1(x+1,y,g);
        rec1(x,y+1,g);
    }
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        
        for(int i=0;i<g1.size();i++)
            for(int j=0;j<g1[i].size();j++)
                if(g1[i][j]==1)
                    rec(i,j,g1,g2);
        
        for(int i=0;i<g1.size();i++)
            for(int j=0;j<g1[i].size();j++)
                if(g2[i][j]==1)
                    rec1(i,j,g2);
        
        int res=0;
        
        for(int i=0;i<g1.size();i++)
            for(int j=0;j<g1[i].size();j++)
                if(g2[i][j]==2)
                    res++, rec1(i,j,g2);
        
        return res;
    }
};