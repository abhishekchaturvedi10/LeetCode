class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> primes = {2,3,5};
        priority_queue<long,vector<long>,greater<>> minHeap;
        unordered_set<long> vis;

        minHeap.push(1);
        vis.insert(1);
        long curr;

        for(int i=0;i<n;i++) {
            curr=minHeap.top();
            minHeap.pop();
            for(int& prime:primes) {
                long nextCurr=curr*prime;
                if(!vis.count(nextCurr)) {
                    minHeap.push(nextCurr);
                    vis.insert(nextCurr);
                }
            }
        }

        return (int)curr;
    }
};