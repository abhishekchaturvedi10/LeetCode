class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int f=0;
        
        while(!f) {
            
            if(s.size()<part.size())
                return s;
            
            string x;
            
            int i=0, ff=0;
            
            while(i<s.size()) {
                
                if(s.size()-i>=part.size()&&s.substr(i,part.size())==part&&!ff) {
                    i=i+part.size();
                    ff=1;
                }
                else
                    x+=s[i++];
            }
            
            if(!ff)
                return s;
            
            s=x;
        }
            
        return s;
    }
};