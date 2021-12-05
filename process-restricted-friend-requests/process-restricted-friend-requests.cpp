class Solution {
public:
    
    vector<int> par;
    
    int find(int i){
        
        if(par[i]==i)
            return i;
        
        return par[i]=find(par[i]);
    }
    
    void Union(int i, int j){
        par[find(i)]=find(j);
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        for(int i=0;i<n;i++)
            par.push_back(i);
        
        vector<bool> res;
        
        for(auto &i:requests) {
            
            int x=find(i[0]), y=find(i[1]);
            
            bool lol=1;
         
            for(auto &j:restrictions) {
                
                int a=find(j[0]), b=find(j[1]);
                
                if((a==x&&b==y) || (b==x&&a==y)) {
                    lol=0;
                    break;
                }
            }
            
            res.push_back(lol);
            
            if(lol)
                Union(x,y);
        }
        
        return res;
    }
};