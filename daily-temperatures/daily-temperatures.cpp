class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        int n=temps.size();
        
        vector<int> res(n);
        
        stack<pair<int,int>> s;
                
        for(int i=0;i<n;i++){
            
            while(!s.empty()&&s.top().first<temps[i]){
                res[s.top().second]=i-s.top().second;
                s.pop();
            }
            
            s.push({temps[i],i});
        }
                
        return res;
    }
};