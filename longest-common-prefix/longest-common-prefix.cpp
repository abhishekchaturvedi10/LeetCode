class Solution {
public:
    
    string LCP(string &s1, string &s2) {
            
        int i=0, j=0;
            
        string prefix;
            
        while(i<s1.size()&&j<s2.size()) {
                
            if(s1[i]!=s2[j])
                break;
                
            prefix.push_back(s1[i]);
                
            i++, j++;
        }
            
        return prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        string res=strs[0];
        
        for(string &s:strs)
            res=LCP(s, res);
        
        return res;
    }
};