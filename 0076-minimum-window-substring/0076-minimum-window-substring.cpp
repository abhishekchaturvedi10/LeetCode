class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> freq;
        
        for(int i=0;i<t.size();i++)
            freq[t[i]]++;
                
        int l=0,r=0,res=1e7,si=-1;
            
        while(r<s.size()) {
            
            freq[s[r]]--;
            
            while(l<=r&&freq[s[l]]<0)
                freq[s[l++]]++;
            
            int f=0;
                        
            for(char i=0;i<=26;i++) {
                if(freq[i+'a']>0 || freq[i+'A']>0) {
                    f=1;
                    break;
                }
            }
        
            if(f==0&&(r-l+1)<res) {
                res=r-l+1;
                si=l;
            }
            
            r++;
        }
        return si==-1?"":s.substr(si,res);
    }
};