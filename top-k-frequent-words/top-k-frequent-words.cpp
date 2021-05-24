class Solution {
public:
    
    struct sorter{
        bool operator()(pair<int,string> p1, pair<int,string> p2){
            if(p1.first==p2.first)
                return p1.second>p2.second;
            return p1.first<p2.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
     
        map<string,int> freq;
        
        for(auto s:words)
            freq[s]++;
        
        priority_queue<pair<int,string>, vector<pair<int,string>>,sorter> pq;
        
        for(auto i:freq)
            pq.push({i.second,i.first});
        
        vector<string> res;
        
        while(k--){
            
            auto p=pq.top();
            
            pq.pop();
            
            res.emplace_back(p.second);
        }
        
        return res;
    }
};