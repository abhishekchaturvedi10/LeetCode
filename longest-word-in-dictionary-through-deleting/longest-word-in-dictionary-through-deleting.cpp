class Solution {
public:
    
    bool isSubSeq(string &s, string &t) {
        
        int j=0;
        
        for(int i=0;i<s.size()&&j<t.size();i++)
            if(s[i]==t[j])
                j++;
        
        return j==t.length();
    }
    
    string findLongestWord(string &s, vector<string>& dictionary) {
        
        string res="";
        
        for(auto &i:dictionary) {
            
            if(isSubSeq(s,i)){
                
                if(i.size()>res.size())
                    res=i;
                else if(i.size()==res.size()&&i<res)
                    res=i;
            }
        }
        
        return res;
    }
};