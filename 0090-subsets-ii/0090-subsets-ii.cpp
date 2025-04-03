class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempList;
        sort(nums.begin(), nums.end());
        backtrack(result, tempList, nums, 0);
        return result;
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int>& tempList, vector<int>& nums, int index) {
        if (index == nums.size()) {
            if (find(result.begin(), result.end(), tempList) == result.end()) 
                result.push_back(tempList);
            return;
        }
        backtrack(result, tempList, nums, index + 1);
        tempList.push_back(nums[index]);
        backtrack(result, tempList, nums, index + 1);
        tempList.pop_back();
    }
};
