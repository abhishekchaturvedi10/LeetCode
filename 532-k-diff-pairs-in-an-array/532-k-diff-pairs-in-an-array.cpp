class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(nums.size()==1)
            return 0;
     
        int i=0, n=nums.size(), j=1, res=0;
        
        sort(nums.begin(), nums.end());
        
        while(j<n) {
            
            if(nums[j]-nums[i]==k) {
                
                res++;
                
                int ii=i;
                while(ii<n&&nums[ii]==nums[i])
                    ii++;
                i=ii;
                
                ii=j;
                while(ii<n&&nums[ii]==nums[j])
                    ii++;
                j=ii;
            }
            else if(nums[j]-nums[i]>k) {
                int ii=i;
                while(ii<n&&nums[ii]==nums[i])
                    ii++;
                i=ii;
            }
            else {
                int ii=j;
                while(ii<n&&nums[ii]==nums[j])
                    ii++;
                j=ii;
            }
                        
            if(i>=j)
                j=i+1;
        }
        
        return res;
    }
};