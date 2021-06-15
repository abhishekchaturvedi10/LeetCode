class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r=0;
        
        while(r<m.size()){
            if(m[r][0]>t)
                break;
            r++;
        }
        
        if(r==0)
            return 0;
        
        if(r==m.size()&&m[r-1].back()<t)
            return 0;
        
        if(binary_search(m[r-1].begin(),m[r-1].end(),t))
            return 1;
        
        return 0;
    }
};