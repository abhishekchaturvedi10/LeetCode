class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> s;
        
        int i=0, j=0, n=nums.size(), res=1;
        
        while(j<n) {
            
            s.insert(nums[j]);
            
            while(*s.rbegin()-*s.begin()>limit) 
                s.erase(s.find(nums[i++]));
            
            res=max(res, j-i+1);
            
            j++;
        }
        
        return res;
    }
};