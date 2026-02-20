class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> maxheap;
        
        for(int i=0;i<k;i++){
            maxheap.push({nums[i],i});
        }
        
        vector<int> res;
        res.push_back(maxheap.top().first);
        
        for(int i=k;i<nums.size();i++){
            maxheap.push({nums[i],i});
            while(maxheap.top().second+k<=i){
                maxheap.pop();
            }
            res.push_back(maxheap.top().first);
        }
        
        return res;
    }
};