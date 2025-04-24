class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums) {
            mp[i]++;
        }
        int cnt=mp.size(), l=0, r=0, res=0;;
        mp.clear();
        while(r<nums.size()) {
            mp[nums[r]]++;
            while(mp.size()==cnt) {
                res+=nums.size()-r;
                mp[nums[l]]--;
                if(mp[nums[l]]==0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return res;
    }
};