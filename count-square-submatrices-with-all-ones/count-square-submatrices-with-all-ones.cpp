class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int res=0;
        for(int i=1;i<m.size();i++){
            res+=m[i][0];
        }
        for(int i=0;i<m[0].size();i++){
            res+=m[0][i];
        }
        for(int i=1;i<m.size();i++){
            for(int j=1;j<m[0].size();j++){
                if(m[i][j]){
                    m[i][j]=min({m[i-1][j], m[i-1][j-1], m[i][j-1]})+1;
                    res+=m[i][j];
                }
            }
        }
        return res;
    }
};