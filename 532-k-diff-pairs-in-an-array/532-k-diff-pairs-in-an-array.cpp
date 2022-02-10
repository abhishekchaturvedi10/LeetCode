class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(nums.size()==1)
            return 0;
        
        map<int, int> m;
                
        for(int i:nums)
            m[i]++;
        
        int res=0;
                
        for(auto i:m) {
            if(m.find(i.first+k)!=m.end()){
                if(k==0&&m[i.first]>1)
                    res++;
                
                if(k!=0)
                    res++;
            }
        }
        
        return res;
    }
};