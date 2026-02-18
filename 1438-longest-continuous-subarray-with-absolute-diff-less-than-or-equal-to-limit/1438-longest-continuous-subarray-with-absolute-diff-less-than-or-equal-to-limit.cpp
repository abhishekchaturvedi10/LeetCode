class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> dec, inc;
        int l = 0, res = 0;

        for(int i=0;i<nums.size();i++) {
            while(dec.size() && nums[i]>dec.back()) {
                dec.pop_back();
            }
            dec.push_back(nums[i]);
            while(inc.size() && nums[i]<inc.back()) {
                inc.pop_back();
            }
            inc.push_back(nums[i]);
            while(dec.front()-inc.front()>limit) {
                if(dec.front() == nums[l]) {
                    dec.pop_front();
                }
                if(inc.front() == nums[l]) {
                    inc.pop_front();
                }
                l++;
            }
            res = max(res, i-l+1);
        }

        return res;
    }
};