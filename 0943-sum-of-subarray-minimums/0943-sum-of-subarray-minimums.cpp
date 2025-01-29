class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> nse(n,n);
        for(int i=0;i<n;i++) {
            while(!s.empty()&&nums[s.top()]>nums[i]) {
                nse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++) {
            while(!s.empty()&&nums[s.top()]>nums[i]) {
                s.pop();
            }
            if(!s.empty()) {
                pse[i]=s.top();
            }
            s.push(i);
        }
        int res=0, mod=1e9+7;
        for(int i=0;i<n;i++) {
            long long int x = (i-pse[i])*(nse[i]-i);
            x=(x%mod)*nums[i];
            res=((res%mod)+(x%mod))%mod;
        }
        return res%mod;
    }
};