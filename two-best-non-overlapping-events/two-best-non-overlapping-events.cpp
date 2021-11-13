class Solution {
public:
    
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end());
        
        int res=0, max_val=0;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto &e:events) {
            
            while(!pq.empty()&&-pq.top().first<e[0]) {
                max_val=max(max_val, pq.top().second);
                pq.pop();
            }
            
            res = max(res, max_val + e[2]);
            
            pq.push({-e[1], e[2]});
        }
        
        return res;
    }
};