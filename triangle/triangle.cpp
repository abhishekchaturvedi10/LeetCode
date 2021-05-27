class Solution {
public:
    
    int dp[205][205];
    
    int rec(vector<vector<int>>& triangle, int row, int index){
        
        if(row==triangle.size()||index>=triangle[row].size())
            return 0;
        
        if(dp[row][index]!=-1)
            return dp[row][index];
        
        return dp[row][index]=triangle[row][index]+min(rec(triangle,row+1,index), rec(triangle,row+1,index+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(triangle,0,0);
    }
};