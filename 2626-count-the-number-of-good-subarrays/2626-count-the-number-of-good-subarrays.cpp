class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l=0, r=0;
        long long res=0, curCnt=0;
        map<int,int> mp;
        while(r<nums.size()) {
            curCnt+=mp[nums[r]];
            mp[nums[r]]++;
            while(curCnt>=k) {
                res+=nums.size()-r;
                mp[nums[l]]--;
                curCnt-=mp[nums[l]];
                l++;
            }
            r++;
        }
        return res;
    }
};