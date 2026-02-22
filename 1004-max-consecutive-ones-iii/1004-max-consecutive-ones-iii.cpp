class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0, r=0, flippedCnt=0, res=0;

        while(r<nums.size()) {
            if(nums[r]==0) {
                flippedCnt++;
            }
            while(flippedCnt>k) {
                if(nums[l]==0) {
                    flippedCnt--;
                }
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }

        return res;
    }
};