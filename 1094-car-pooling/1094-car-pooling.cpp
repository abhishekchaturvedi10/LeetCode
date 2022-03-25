class Solution {
public:
    
    static bool cmp(vector<int> v1, vector<int> v2) {
        
        if(v2[1]==v1[1])
            return v2[2]>v1[2];
        
        return v2[1]>v1[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
     
        sort(trips.begin(), trips.end(), cmp);
        
        int total=0;
        
        unordered_map<int,int> removed;
        
        for(int i=0;i<trips.size();i++) {
                        
            for(int j=0;j<i;j++) {
                
                if(trips[j][2]<=trips[i][1]&&removed[j]==0) {
                    
                    total-=trips[j][0];
                    
                    removed[j]=1;
                }
            }
            
            total+=trips[i][0];
            
            if(total>capacity)
                return 0;
        }
        
        return 1;
    }
};