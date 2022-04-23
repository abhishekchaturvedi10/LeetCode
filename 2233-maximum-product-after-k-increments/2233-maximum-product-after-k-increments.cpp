class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        if(nums.size()==1)
            return nums[0]+k;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int& n:nums)
            pq.push(n);
        
        while(k) {
            
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
                        
            if(x==y) {
                pq.push(x+1);
                pq.push(y);
                k--;
                continue;
            }
            
            if(y-x>=k)
                x+=k, k=0;
            else
                k-=(y-x),x=y;
            
            pq.push(x);
            pq.push(y);
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