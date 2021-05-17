class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> copy=nums;
        
        sort(copy.begin(),copy.end());
        
        int i,j;
        
        for(i=0;i<nums.size();i++)
            if(nums[i]!=copy[i])
                break;
        
        for(j=nums.size()-1;j>=0;j--)
            if(nums[j]!=copy[j])
                break;
        
        if(j<i)
            return 0;
        
        return j-i+1;
    }
};