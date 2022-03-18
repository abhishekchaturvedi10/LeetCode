class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mapstot;
        unordered_map<char,char> mapttos;
        
        for(int i=0;i<s.size();i++) {
            
            if(mapstot.find(s[i])==mapstot.end()&&mapttos.find(t[i])==mapttos.end()) {
                mapstot[s[i]]=t[i];
                mapttos[t[i]]=s[i];
            }
            else if(mapstot[s[i]]!=t[i] or mapttos[t[i]]!=s[i]){
                return 0;
            }
        }
        
        return 1;
    }
};