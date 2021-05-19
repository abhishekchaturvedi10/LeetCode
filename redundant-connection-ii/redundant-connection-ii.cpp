class Solution {
public:
    
    vector<int> parent;
    
    int find(int i){
        
        if(parent[i]==i)
            return i;
        
        return parent[i] = find(parent[i]);
    }
    
    void Union(int i, int j){
        parent[find(i)]=find(j);
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
       
        int n=edges.size();
                
        vector<int> inDeg(n+1,0);
        
        for(auto edge:edges)
            inDeg[edge[1]]++;
        
        vector<int> res(2);
        
        parent.resize(n+1);
        
        for(int i=0;i<n;i++){
            for(int k=0;k<=n;k++)
                parent[k]=k;
            inDeg[edges[i][1]]--;
            int cycleFound=0, check=0;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(inDeg[edges[j][0]]>1||inDeg[edges[j][1]]>1)
                    check=1;
                int x=find(edges[j][0]), y=find(edges[j][1]);
                if(x==y)
                    cycleFound=1;
                else
                    Union(x,y);
            }
            if(!cycleFound&&!check){
                res[0]=edges[i][0];
                res[1]=edges[i][1];
            }
            inDeg[edges[i][1]]++;
        }
        return res;
    }
};