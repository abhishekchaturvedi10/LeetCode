class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(0);
        
        stack<int> s;
        
        int res=INT_MIN;
        
        for(int i=0;i<heights.size();i++){
            
            while(!s.empty()&&heights[s.top()]>heights[i]){
                
                int h=heights[s.top()];
                
                s.pop();
                
                if(s.empty())
                    res=max(res,h*i);
                else
                    res=max(res,(i-s.top()-1)*h);
            }
            
            s.push(i);
        }
        
        return max(res,0);
    }
};