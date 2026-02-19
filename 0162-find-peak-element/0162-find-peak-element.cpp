class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l=0, r=nums.size()-1;

        while(r>=l) {
            int m = l+(r-l)/2;
            bool isPeak = true;
            int moveRight = 0, moveLeft = 0;
            if(m>0 && nums[m-1]>nums[m]) {
                isPeak = false;
                moveLeft = 1;
            }
            if(m<nums.size()-1 && nums[m+1]>nums[m]) {
                isPeak = false;
                moveRight = 1;
            }
            if(isPeak) {
                return m;
            }
            if(moveRight) {
                l=m+1;
            } else {
                r=m-1;
            }
        }

        return -1;
    }
};