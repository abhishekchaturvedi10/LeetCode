class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int i=0, res=1, l=0;
        long long s=0;

        while(i<nums.size()) {
            s+=nums[i];
            while(s+k < ((long long)(nums[i])*(i-l+1))) {
                s-=nums[l];
                l++;
            }
            res=max(res,i-l+1);
            i++;
        }

        return res;
    }
};