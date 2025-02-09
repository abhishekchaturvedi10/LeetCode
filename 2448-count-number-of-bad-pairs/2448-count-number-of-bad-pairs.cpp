class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long,int> mp;
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++) {
            res+=(i-mp[nums[i]-i]);
            mp[nums[i]-i]++;
        }
        return res;
    }
};