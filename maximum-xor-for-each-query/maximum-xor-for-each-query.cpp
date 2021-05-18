class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> res;
        
        int x=(1<<maximumBit)-1, y=nums[0];
        
        for(int i=1;i<nums.size();i++)
            y^=nums[i];
        
        res.push_back(y^x);
        
        for(int i=1;i<nums.size();i++)
            y^=nums[nums.size()-i], res.push_back(y^x);
        
        return res;
    }
};