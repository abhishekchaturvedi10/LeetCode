class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()&&k>0&&nums[i]<0;i++) 
            nums[i]*=-1, k--;
        
        if(k>0) {
            
            int x=INT_MAX, ind=0;
            
            for(int i=0;i<nums.size();i++)
                if(nums[i]>=0&&nums[i]<x)
                    ind=i, x=nums[i];
            
            if(k&1)
                nums[ind]*=-1;
        }
        
        int res=0;
        
        for(int i:nums)
            res+=i;
        
        return res;
    }
};