class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
                
        int res=0, n=nums.size();
        
        vector<vector<int>> dpp(n, vector<int>(505, 1));
        vector<vector<int>> dpn(n, vector<int>(505, 1));
        
        for(int i=1;i<n;i++){
                        
            for(int j=0;j<i;j++){
                
                if(nums[i]-nums[j]<0) {
                    dpn[i][nums[j]-nums[i]] = dpn[j][nums[j]-nums[i]] + 1;
                    res=max(res, dpn[i][nums[j]-nums[i]]);
                }
                else {
                    dpp[i][nums[i]-nums[j]] = dpp[j][nums[i]-nums[j]] + 1;
                    res=max(res, dpp[i][nums[i]-nums[j]]);
                }
            }
        }
        
        return res;
    }
};