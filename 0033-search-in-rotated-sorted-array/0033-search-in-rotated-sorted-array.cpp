class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int r=nums.size()-1, l=0;

        while(r>=l) {
            int m = l+(r-l)/2;
            if(nums[m]==target) {
                return m;
            }
            if(nums[r]>nums[m]) {
                if(target>=nums[m] && target<=nums[r]) {
                    l=m+1;
                } else {
                    r=m-1;
                }
            } else {
                if(target>=nums[l]&&target<=nums[m]) {
                    r=m-1;
                } else {
                    l=m+1;
                }
            }
        }

        return -1;
    }
};