class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& s) {
        
        priority_queue<vector<int>> pq;
        
        unordered_map<int,int> mp;
        
        for(int c:s)
            mp[c]++;
        
        for(auto i:mp)
            pq.push({i.second,i.first});
        
        vector<int> res(s.size());
        
        int i=0,j=1;
        
        while(pq.size()>1){
            
            auto a=pq.top()[0],c=pq.top()[1];
            pq.pop();
            
            auto b=pq.top()[0],d=pq.top()[1];
            pq.pop();
                        
            res[i]=c;
            i+=2;
            a--;
                
            res[j]=d;
            j+=2;
            b--;
            
            if(a)
                pq.push({a,c});
            
            if(b)
                pq.push({b,d});
        }
        
        if(!pq.empty()){
            
            auto a=pq.top()[0],c=pq.top()[1];
            pq.pop();
                        
            for(int k=i;k<s.size()&&a;k+=2){
                res[k]=c;
                a--;
                i+=2;
            }
        }
        
        return res;
    }
};