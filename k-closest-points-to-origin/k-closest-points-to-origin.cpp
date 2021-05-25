class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
    priority_queue<pair<long double,vector<int>>> pq;
        
        for(auto const& i:points){
            
            long double d=sqrt(1.0*i[0]*i[0]+1.0*i[1]*i[1]);
                                
            pq.push({d,i});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<vector<int>> res;
        
        while(k--){
            
            auto p=pq.top();
            
            pq.pop();
            
            res.push_back(p.second);
        }
        
        return res;
    }
};