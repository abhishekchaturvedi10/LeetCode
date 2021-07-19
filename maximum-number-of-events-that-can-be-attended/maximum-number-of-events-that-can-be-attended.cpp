class Solution {
public:
    
    int maxEvents(vector<vector<int>>& events) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        sort(events.begin(), events.end());
        
        int res=0, i=0;
        
        for(int d=1;d<=100000;d++) {
            
            while(pq.size()&&pq.top()<d) 
                pq.pop();
            
            while(i<events.size()&&d==events[i][0])
                pq.push(events[i++][1]);
            
            if(pq.size()) {
                pq.pop();
                res++;
            }
        }
        
        return res;
    }
};