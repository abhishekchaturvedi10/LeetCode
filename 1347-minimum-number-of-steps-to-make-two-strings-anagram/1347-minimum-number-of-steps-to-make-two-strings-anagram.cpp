class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char,int> m;
        
        for(char& c:s)
            m[c]++;
        
        int res=0;
        
        for(char& c:t){
            if(m[c]==0) 
                res++;
            else
                m[c]--;
        }
            
        return res;
    }
};