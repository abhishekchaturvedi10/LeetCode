class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        vector<int> v(s.size()+1);
        
        for(int i=s.size()-1;i>=0;i--) {
            
            if(s[i]=='0')
                v[i]=v[i+1]+1;
            else
                v[i]=v[i+1];
        }
        
        int one=0, res=INT_MAX;
        
        for(int i=0;i<s.size();i++) {
            
            if(s[i]=='1')
                one++;
            
            res=min(res, one+v[i+1]);
        }
        
        return min({res, one, v[0]});
    }
};