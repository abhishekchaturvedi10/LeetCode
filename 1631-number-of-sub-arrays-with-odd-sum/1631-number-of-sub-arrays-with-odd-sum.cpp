class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0, even=0;
        int res=0, s=0, mod=1e9 + 7;
        for(int i:arr) {
            s+=i;
            if(s&1) {
                res=((res%mod + even%mod) + 1)%mod;
                odd++;
            } else {
                res=((res%mod + odd%mod))%mod;
                even++;
            }
        }
        return res;
    }
};