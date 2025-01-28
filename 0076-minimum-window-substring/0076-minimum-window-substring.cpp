class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> freqT;
        
        for(int i=0;i<t.size();i++)
            freqT[t[i]]++;
        
        unordered_map<char,int> freqS;
        
        int l=0,r=0,res=INT_MAX;
        
        string ans="";
        
        while(r<s.size()) {
            
            freqS[s[r]]++;
            
            while(l<=r&&freqS[s[l]]>freqT[s[l]])
                freqS[s[l++]]--;
            
            int f=0;
                        
            for(char i=0;i<=26;i++) {
                if((freqT[i+'a']>freqS[i+'a']) || (freqT[i+'A']>freqS[i+'A'])) {
                    f=1;
                    break;
                }
            }
        
            if(f==0&&(r-l+1)<res) {
                res=r-l+1;
                ans=s.substr(l,res);
            }
            
            r++;
        }
        
        return ans;
    }
};