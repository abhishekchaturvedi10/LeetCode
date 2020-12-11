class Solution {
public:
    vector<int> ans;
    void bs(vector<int> nums, int l, int r, int target) {
        if(l>r) return;
        while(r>=l){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                ans.push_back(mid+1); return;
            }
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            ans.clear();
            if(nums[i]<=target){
                ans.push_back(i+1);
                int newtarget=target-nums[i];
                if(newtarget>nums[i])
                    bs(nums, i, nums.size()-1, newtarget);
                else 
                    bs(nums, 0, i-1, newtarget);
                if(ans.size()==2){
                    sort(ans.begin(), ans.end());
                    break;
                }
            } 
        }
        return ans;
    }
};
