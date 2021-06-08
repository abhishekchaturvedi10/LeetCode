class Solution {
public:
    
    #define ss second
    #define ff first
    
    string frequencySort(string s) {
        
        unordered_map<char,int> freq;
        
        for(char c:s)
            freq[c]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto i:freq)
            pq.push({i.ss,i.ff});
        
        string res;
        
        while(!pq.empty()){
            
            int x=pq.top().ff;
            char y=pq.top().ss;
            
            pq.pop();
                    
            while(x--)
                res+=y;
        }
        
        return res;
    }
};