

class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& a) {
        
        // Sort in non decreasing deadline
        sort(a.begin(),a.end(),cmp);
                        
        priority_queue<int> pq;
        
        int time=0;
        
        for(auto i:a){
            
            time+=i[0];
            
            pq.push(i[0]);
            
            // If we take the current course and we have exceeded the time then we will remove some courses with maximum durations
            
            while(time>i[1]){
                
                time-=pq.top();
                
                pq.pop();
            }
        }
        
        return pq.size();
    }
};