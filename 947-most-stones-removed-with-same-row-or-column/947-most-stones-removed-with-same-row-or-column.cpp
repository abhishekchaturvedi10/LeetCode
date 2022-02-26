class Solution {
public:
    vector<int> parent;
    
    int find(int i){
        if(parent[i]==i)
            return i;
        return parent[i]=find(parent[i]);
    }
    
    void Union(int x, int y){
        parent[find(x)]=find(y);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        for(int i=0;i<stones.size();i++){
            parent.push_back(i);
        }
        
        unordered_map<int,vector<int>> row, column;
        
        for(int i = 0; i < stones.size(); i++){
            row[stones[i][0]].push_back(i);
            column[stones[i][1]].push_back(i);
        }
        
        for(int i = 0; i < stones.size(); i++) {
            
		    for(int j : row[stones[i][0]]) 
                Union(i, j);
		    
            for(int j : column[stones[i][1]]) 
                Union(i, j);
	    }

	    unordered_set<int> unique;
        
	    for(int n : parent) 
            unique.insert(find(n));
        
	    return stones.size() - unique.size();
    }
};