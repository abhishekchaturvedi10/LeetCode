class Solution {
public:
    
    bool check(vector<int> &a, vector<int> &b) {
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return 0;
        return 1;
    }
    
    bool checkInclusion(string p, string s) {
        
        int n=s.size(), m=p.size();

        if(m>n)
            return false;
        
        vector<int> smap(26), pmap(26);
        
        for(int i=0;i<m;i++)
            smap[s[i]-'a']++, pmap[p[i]-'a']++;
                
        for(int i=0;i<n-m;i++){
            
            if(check(smap, pmap))
                return true;
            
            smap[s[i]-'a']--;
            smap[s[i+m]-'a']++;
        }
        
        if(check(smap, pmap))
            return true;
        
        return false;
    }
};