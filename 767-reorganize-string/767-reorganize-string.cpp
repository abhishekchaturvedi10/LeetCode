class Solution {
public:
    string reorganizeString(string s) {
        
        priority_queue<vector<int>> pq;
        
        unordered_map<char,int> mp;
        
        for(char c:s)
            mp[c]++;
        
        for(auto i:mp)
            pq.push({i.second,i.first});
        
        string res;
        
        for(int i=0;i<s.size();i++)
            res+='*';
            
        bool can=true;
        
        int i=0,j=1;
        
        while(pq.size()>1){
            
            auto a=pq.top()[0],c=pq.top()[1];
            pq.pop();
            
            auto b=pq.top()[0],d=pq.top()[1];
            pq.pop();
                        
            if(j>=s.size())
                return "";
            
            res[i]=(char)c;
            i+=2;
            a--;
                
            res[j]=(char)d;
            j+=2;
            b--;
            
            if(a)
                pq.push({a,(char)c});
            
            if(b)
                pq.push({b,(char)d});
        }
        
        if(!pq.empty()){
            
            auto a=pq.top()[0],c=pq.top()[1];
            pq.pop();
            
            for(int k=i;k<s.size()&&a;k+=2){
                res[k]=(char)c;
                a--;
                i+=2;
            }
                
            if(a)
                return "";
        }
        
        return res;
    }
};