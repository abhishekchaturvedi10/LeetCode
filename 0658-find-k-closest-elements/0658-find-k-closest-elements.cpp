struct sorter{
    
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2){
        
        if(p1.first==p2.first)
            return p1.second>p2.second;
        
        return p1.first>p2.first;
    }
};

class Solution {
public:
 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            
        for(int i:arr)
            pq.push({abs(i-x),i});
        
        vector<int> res(k);
                
        while(k--){        
            res[k]=pq.top().second;
            pq.pop();
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};