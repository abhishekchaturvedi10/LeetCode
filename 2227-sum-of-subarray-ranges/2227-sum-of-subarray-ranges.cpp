class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
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
        long long res=0;
        for(int i=0;i<n;i++) {
            res -= (long long) (i-pse[i])*(nse[i]-i)*nums[i];
        }
        s=stack<int>();
        vector<int> nge(n,n);
        vector<int> pge(n,-1);
        for(int i=0;i<n;i++) {
            while(!s.empty()&&nums[s.top()]<nums[i]) {
                nge[s.top()]=i;
                s.pop();
            }
            if(!s.empty()) {
                pge[i]=s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++) {
            res += (long long) (i-pge[i])*(nge[i]-i)*nums[i];
        }
        return res;
    }
};