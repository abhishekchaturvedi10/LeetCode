class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size(), maxEndDay=-1;
        for(auto &event:events) {
            maxEndDay=max(maxEndDay,event[1]);
        }
        sort(events.begin(),events.end());
        int res=0, i=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int d=1;d<=maxEndDay;d++) {
            while(!pq.empty()&&pq.top()<d) {  
                pq.pop();
            }
            while(i<n&&d>=events[i][0]&&d<=events[i][1]) {
                pq.push(events[i++][1]);
            }
            if(!pq.empty()) {
                pq.pop();
                res++;
            }
        }
        return res;
    }
};