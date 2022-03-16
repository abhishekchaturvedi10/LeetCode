class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> h;
        
        vector<int> res(nums.size(),-1000000);
        
        h.push({nums[0],0});
        
        for(int i=1;i<nums.size();i++) {
            if(i<k) {
                h.push({nums[i],i});
            }
            else{
                if(nums[i]>h.top()[0]) {
                    h.pop();
                    h.push({nums[i],i});
                }
            }
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