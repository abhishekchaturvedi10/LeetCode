class Solution {
public:
    vector<int> color;
    bool dfs(int vertex,vector<vector<int>> &graph)
    {
        color[vertex]=1;
        for(auto u:graph[vertex])
        {
            if(color[u]==0) {  
                if(dfs(u,graph))
                   return true;
             }
            
            else if(color[u]==1)
                return true;
        }
        color[vertex]=2;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>graph(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            graph[u].push_back(v);
            
        }
        color.assign(numCourses,0);
        
        for(int i=0;i<numCourses;i++ ){
            if(color[i]!=2)
                if(dfs(i,graph))
                    return false;
        }
        
        return true;
    }
};