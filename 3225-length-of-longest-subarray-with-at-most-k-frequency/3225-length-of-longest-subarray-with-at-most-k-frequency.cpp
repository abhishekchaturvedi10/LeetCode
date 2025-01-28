class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[nums[0]]=1;
        int l=0, r=1, res=1;
        while(r<nums.size()) {
            while(freq[nums[r]]==k) {
                freq[nums[l++]]--;
            }
            res=max(res,r-l+1);
            freq[nums[r++]]++;
        }
        return res;
    }
};