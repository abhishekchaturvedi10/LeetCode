class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0]=1;
        int s=0, ans=0;
        for(int i:nums){
            s+=i;
            ans+=m[s-k];
            m[s]++;
        }
        return ans;
    }
};