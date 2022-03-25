class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> net(1005,0);
        
        for(int i=0;i<trips.size();i++) {
                        
            net[trips[i][1]] += trips[i][0];
            net[trips[i][2]] -= trips[i][0];
        }
        
        int total=0;
        
        for(int i=0;i<=1000;i++) {
            total += net[i];
            if(total>capacity)
                return 0;
        }
        
        return 1;
    }
};