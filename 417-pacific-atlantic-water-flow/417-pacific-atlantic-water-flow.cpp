class Solution {
public:
    
    vector<vector<int>> vis, vis1;
    
    void dfs(vector<vector<int>> &h,int i,int j) {
        
        if(vis[i][j]!=0)
            return;
        
        vis[i][j]=1;
                
        if(i>0&&h[i-1][j]>=h[i][j])
            dfs(h,i-1,j);
        if(j>0&&h[i][j-1]>=h[i][j])
            dfs(h,i,j-1);
        if(i+1<h.size()&&h[i+1][j]>=h[i][j])
            dfs(h,i+1,j);
        if(j+1<h[0].size()&&h[i][j+1]>=h[i][j])
            dfs(h,i,j+1);
    }
    
    void dfs1(vector<vector<int>> &h,int i,int j) {
        
        if(vis1[i][j]!=0)
            return;
        
        vis1[i][j]=1;
                
        if(i>0&&h[i-1][j]>=h[i][j])
            dfs1(h,i-1,j);
        if(j>0&&h[i][j-1]>=h[i][j])
            dfs1(h,i,j-1);
        if(i+1<h.size()&&h[i+1][j]>=h[i][j])
            dfs1(h,i+1,j);
        if(j+1<h[0].size()&&h[i][j+1]>=h[i][j])
            dfs1(h,i,j+1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m=heights.size(), n=heights[0].size();
                
        for(int i=0;i<m;i++)
            vis.push_back(vector<int>(n,0)), vis1.push_back(vector<int>(n,0));
        
        for(int i=0;i<m;i++)
            dfs(heights,i,0), dfs1(heights,i,n-1);
        
        for(int i=0;i<n;i++)
            dfs(heights,0,i), dfs1(heights,m-1,i);
        
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++)
                if(vis[i][j]&&vis1[i][j])
                    res.push_back({i,j});
        
        return res;
    }
};