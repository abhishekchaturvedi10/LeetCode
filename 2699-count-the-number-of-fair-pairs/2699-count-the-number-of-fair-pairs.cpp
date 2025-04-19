class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long res=0;
        for(int i=0;i<nums.size()-1;i++) {
            int low = upper_bound(nums.begin()+i+1, nums.end(), lower-nums[i]-1)-nums.begin();
            int up = lower_bound(nums.begin()+i+1, nums.end(), upper-nums[i]+1)-nums.begin();
            res+=up-low;
        }
        return res;
    }
};