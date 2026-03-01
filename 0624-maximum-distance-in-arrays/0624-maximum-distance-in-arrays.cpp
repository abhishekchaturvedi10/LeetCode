class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int m=arrays.size(), mn=arrays[0][0], mx=arrays[0][arrays[0].size()-1], res=0;

        for(int i=1;i<m;i++) {
            int n=arrays[i].size(), curmn=arrays[i][0], curmx=arrays[i][n-1];
            res=max(curmx-mn,res);
            res=max(mx-curmn,res);
            mx=max(mx,curmx);
            mn=min(mn,curmn);
        }

        return res;
    }
};