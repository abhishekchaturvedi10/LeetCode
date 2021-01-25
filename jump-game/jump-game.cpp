class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        if(!nums[0])
            return false;
        int jumps=nums[0], i=1, mx=nums[0];
        while(i<nums.size()){
            if(mx>=nums.size()-1)
                return true;
            int j=i, x=mx;
            while(j<nums.size()&&j<=x){
                mx=max(j+nums[j],mx);
                j++;
            }
            i=j;
            if(x==mx)
                return false;
        }
        return false;
    }
};
