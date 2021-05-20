class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
        int n=a.size(), m=b.size();
        
        vector<vector<int>> res;
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<k&&i<n;i++)
            pq.push({a[i]+b[0],{i,0}});
        
        while(k--&&!pq.empty()){
            
            auto p=pq.top();
            
            pq.pop();
            
            int i=p.second.first, j=p.second.second;
            
            res.push_back({a[i],b[j]});
            
            if(j<m-1){
                pq.push({a[i]+b[j+1],{i,j+1}});
            }
        }
        
        return res;
    }
};