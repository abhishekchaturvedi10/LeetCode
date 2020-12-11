class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(r>l){
            if(nums[l]+nums[r]==target) 
                break;
            else if(nums[l]+nums[r]>target)
                r--;
            else l++;
        }
        vector<int> ans; 
        ans.push_back(l+1);
        ans.push_back(r+1);
        return ans;
    }
};