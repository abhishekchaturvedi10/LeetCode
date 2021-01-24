class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int i:nums)
            freq[i]++;
        vector<int> ans;
        if(freq.size()==nums.size()){
            for(auto i:freq)
                ans.push_back(i.first);
            return ans;
        }
        priority_queue<pair<int,int>> maxheap;
        for(auto i:freq)
            maxheap.push({i.second,i.first});
        while(k--){
            auto p=maxheap.top();
            maxheap.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
