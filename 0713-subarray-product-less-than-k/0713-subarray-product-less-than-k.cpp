class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) {
            return 0;
        }
        int l=0, r=0, res=0;
        long long int curProd=1;
        while(r<nums.size()) {
            curProd*=nums[r];
            while(r>=l&&curProd>=k) {
                curProd/=nums[l++];
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
};