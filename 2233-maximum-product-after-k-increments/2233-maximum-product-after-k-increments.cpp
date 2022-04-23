class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int& n:nums)
            pq.push(n);
        
        while(k--) {
            int x=pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }
        
        long long res=1;
        
        while(pq.size()) {
            res*=pq.top();
            res%=1000000007;
            pq.pop();
        }
        
        return res%1000000007;
    }
};