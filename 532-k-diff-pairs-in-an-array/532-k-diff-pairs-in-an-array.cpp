class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(nums.size()==1)
            return 0;
        
        unordered_map<int, int> m;
                
        for(int i:nums)
            m[i]++;
        
        int res=0;
                
        for(auto &i:m) {
            if(k==0&&m[i.first]>1)
                res++;
                
            if(k!=0&&m.find(i.first+k)!=m.end())
                res++;
        }
        
        return res;
    }
};