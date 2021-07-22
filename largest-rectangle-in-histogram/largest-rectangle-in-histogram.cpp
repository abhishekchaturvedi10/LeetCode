class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        
        int n = heights.size();
        
        int res = INT_MIN;
        
        int i = 0;
        
        while(i<n) {
            
            if(s.empty() || heights[s.top()]<=heights[i])
                s.push(i++);
            
            else {
                
                int tp = s.top();
                
                s.pop();
                
                int width;
                
                if(s.empty()) 
                    width = i;
                else
                    width = i-s.top()-1;
                
                res = max(res, width*heights[tp]);                    
            }
        }
        
        while(!s.empty()) {
            
            int tp = s.top();
            
            s.pop();
            
            int width;
                
            if(s.empty()) 
                width = i;
            else
                width = i-s.top()-1;
                
            res = max(res, width*heights[tp]);
        }
        
        return res;
    }
};