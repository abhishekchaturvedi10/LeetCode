struct sorter{
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2){
        if(p1.first==p2.first)
            return p2.second>p1.second;
        return p1.first<p2.first;
    }
};
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size(), m=worker.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,sorter> pq;
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