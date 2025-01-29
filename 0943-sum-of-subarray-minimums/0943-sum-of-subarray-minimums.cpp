class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++) {
            while(!s.empty()&&nums[s.top()]>nums[i]) {
                nse[s.top()]=i;
                s.pop();
            }
            if(!s.empty()) {
                pse[i]=s.top();
            }
            s.push(i);
        }
        int res=0, mod=1e9+7;
        for(int i=0;i<n;i++) {
            res += (long) (i-pse[i])*(nse[i]-i)%mod * nums[i]%mod;
            res%=mod;
        }
        return res;
    }
};