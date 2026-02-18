class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=1, l=0, r=0;
        while(r<nums.size()) {
            if(nums[r]-nums[l]>k) {
                res++;
                l=r;
            } else {
                r++;
            }
        }
        return res;
    }
};