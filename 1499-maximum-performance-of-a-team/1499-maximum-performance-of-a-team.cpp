class Solution {
public:
    int maxPerformance(int n, vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end(),greater<>());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long int curSum=0, res=0;
        for(auto& x:v) {
            pq.push(x.second);
            curSum+=x.second;
            if(pq.size()>k) {
                curSum-=pq.top();
                pq.pop();
            }
            res=max(res,curSum*x.first);
        }
        int mod = 1e9+7;
        return res%mod;
    }
};