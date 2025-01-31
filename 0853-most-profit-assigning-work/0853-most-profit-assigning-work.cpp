class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size(), m=worker.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++) {
            pq.push({profit[i],difficulty[i]});
        }
        sort(worker.begin(),worker.end());
        int res=0;
        for(int i=m-1;i>=0;i--) {
            while(!pq.empty()&&pq.top().second>worker[i]) {
                pq.pop();
            }
            if(pq.empty()) {
                break;
            }
            res+=pq.top().first;
        }
        return res;
    }
};