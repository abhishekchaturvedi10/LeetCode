class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> h;
        
        vector<int> res(nums.size(),-1000000);
                
        for(int i=0;i<nums.size();i++) {
            
            h.push({nums[i],i});
            
            if(h.size()>k)
                h.pop();
        }
        
        while(!h.empty()) {
            
            res[h.top()[1]]=h.top()[0];
            
            h.pop();
        }
        
        vector<int> ans;
        
        for(int i:res)
            if(i!=-1000000)
                ans.push_back(i);
        
        return ans;
    }
};