class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
                
        for(int &i:nums) {
            
            if(m[i-1].empty()) {
                
                m[i].push(1);
                                
            }else {
                
                int x=m[i-1].top();
                
                m[i-1].pop();
                
                m[i].push(x+1);
            }
        }
        
        for(auto &i:m){
            
            if(i.second.size()==0)
                continue;
            
            if(i.second.top()<3)
                return 0;
        }
        
        return 1;
    }
};