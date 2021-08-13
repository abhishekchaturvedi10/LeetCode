class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        map<int, int> m;
        
        for(int i:arr) {
            if(i%2==0)
                m[i]++;
        }
        
        for(int i:arr) {
            
            if(i%2){
                if(m[i*2]==0)
                    return 0;
                m[i*2]--;
            }
        }
        
        for(auto p:m) {
            
            int x=p.second;
                        
            while(x) {
                
                if(p.first>0&&m[p.first*2]==0) {
                    cout<<p.first;
                    return 0;
                }
                
                if(p.first<0&&m[p.first*2]==0){
                    break;    
                }
                
                x--;
                
                m[p.first*2]--;
            }
            
            m[p.first]=x;
        }
        
        for(auto p:m) 
            if(p.second>0)
                return 0;
        
        return 1;
    }
};