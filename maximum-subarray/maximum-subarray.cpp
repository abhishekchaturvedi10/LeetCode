class Solution {
public:
    int ans=(int)(-pow(2,31)),cur=0;
    int maxSubArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            if(cur>ans) ans=cur;
            if(cur<0) cur=0;
        }
        return ans;
    }
};
