class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> res(nums.size());
        
        for(int i=0;i<nums.size();i++) {
            
            int f=0;
            
            for(int j=1;j<nums.size();j++) {
                
                if(nums[(i+j)%nums.size()]>nums[i]) {
                    
                    res[i]=nums[(i+j)%nums.size()];
                    
                    f=1;
                    
                    break;
                }
            }
            
            if(!f)
                res[i]=-1;
        }
        
        return res;
    }
};