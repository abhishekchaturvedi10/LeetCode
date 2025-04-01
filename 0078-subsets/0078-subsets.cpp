class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempList;
        backtrack(result, tempList, nums, 0);
        return result;
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int>& tempList, vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(tempList);
            return;
        }
        
        backtrack(result, tempList, nums, index + 1);
        
        tempList.push_back(nums[index]);
        backtrack(result, tempList, nums, index + 1);
        tempList.pop_back();
    }
};
