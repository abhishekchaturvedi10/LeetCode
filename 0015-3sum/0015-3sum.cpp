class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) {
                break;
            }
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int low = i+1, high = nums.size()-1;
            while(high>low) {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum>0) {
                    high--;
                } else if(sum<0) {
                    low++;
                } else {
                    res.push_back({nums[i],nums[low],nums[high]});
                    int last_low_occurrence = nums[low], last_high_occurrence = nums[high];
                    while(low<high && nums[low]==last_low_occurrence) {
                        low++;
                    }
                    while(low<high && nums[high]==last_high_occurrence) {
                        high--;
                    }
                }
            }
        }

        return res;
    }
};