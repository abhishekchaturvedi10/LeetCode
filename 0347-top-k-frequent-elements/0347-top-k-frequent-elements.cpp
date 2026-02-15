class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        
        for(int& i:nums) {
            freq[i]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(auto& x:freq) {
            buckets[x.second].push_back(x.first);
        }

        vector<int> res;

        for(int i=buckets.size()-1;i>=0&&res.size()<k;i--) {
            for(int& j:buckets[i]) {
                res.push_back(j);
                if(res.size()==k) {
                    break;
                }
            }
        }

        return res;
    }
};