class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        
        int n=q.size();
        vector<pair<double,int>> rate;
        for(int i=0;i<n;i++) {
            rate.push_back({w[i]*1.0/q[i],q[i]});
        }
        sort(rate.begin(),rate.end());

        double currTotalQuality = 0;
        double totalCost = 1e12;
        
        priority_queue<int> workers;
        for(int i=0;i<n;i++) {
            workers.push(rate[i].second);
            currTotalQuality += rate[i].second;
            if(workers.size()>k) {
                currTotalQuality -= workers.top();
                workers.pop();
            }
            if(workers.size()==k) {
                totalCost = min(totalCost,currTotalQuality*rate[i].first);
            }
        }
        
        return totalCost;
    }
};