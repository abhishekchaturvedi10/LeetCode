class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int t) {
        
        int m=g.size(), n=g[0].size(), l=0, r=m*n-1;
        
        while(r>=l) {
            
            int mid = l+(r-l)/2;
            
            int v=g[mid/n][mid%n];
            
            if(v==t)
                return 1;
            
            if(v>t)
                r=mid-1;
            else
                l=mid+1;
        }
        
        return 0;
    }
};