class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        
        vector<vector<int>> res;
        
        int i=0, j=0;
        
        while(i<a.size()&&j<b.size()){
            
            if(a[i][0]>b[j][1]){   
                j++;
            }else if(b[j][0]>a[i][1]){
                i++;
            }else{
                
                res.push_back({max(a[i][0],b[j][0]), min(a[i][1], b[j][1])});
                if(a[i][1]<b[j][1])
                    i++;
                else
                    j++;
            }
        }
        
        return res;
    }
};