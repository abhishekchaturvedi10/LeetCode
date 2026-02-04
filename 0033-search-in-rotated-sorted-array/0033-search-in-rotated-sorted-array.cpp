class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(r>=l) {
            int m=l+(r-l)/2;
            if(nums[m]==target) {
                return m;
            }
            if(nums[r]>nums[m]) {
                if(target>nums[m]&&target<=nums[r]) {
                    l=m+1;
                } else {
                    r=m-1;
                }
            } else {
                if(target>=nums[l]&&nums[m]>target) {
                    r=m-1;
                } else {
                    l=m+1;
                }
            }
        }
        return -1;
    }
};