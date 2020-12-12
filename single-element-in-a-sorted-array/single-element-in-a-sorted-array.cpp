class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int l=0,r=nums.size()-1,mid;
        while(r>=l){
            mid=(l+r)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]) break;
            if(mid&1){
                if(nums[mid]==nums[mid-1])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else{
                if(nums[mid]==nums[mid-1])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return nums[mid];
    }
};
