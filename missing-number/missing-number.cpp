class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int x=0;
        
        for(int i=1;i<=nums.size();i++)
            x^=i;
        
        for(int i:nums)
            x^=i;
        
        return x;
    }
};