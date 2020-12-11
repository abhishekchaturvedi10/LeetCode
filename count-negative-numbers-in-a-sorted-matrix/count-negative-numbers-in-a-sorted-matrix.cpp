class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int l=0,r=grid[i].size()-1;
            while(r>=l){
                int mid=(l+r)/2;
                if(grid[i][mid]>=0) l=mid+1;
                else{
                    ans+=r-mid+1; r=mid-1;
                }
            }
        }
        return ans;
    }
};
