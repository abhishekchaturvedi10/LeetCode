class Solution {
public:
    bool check(vector<int> &a, vector<int> &b){
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(), m=p.size();
        vector<int> ans;
        if(m>n)
            return ans;
        vector<int> smap(26), pmap(26);
        for(int i=0;i<m;i++)
            smap[s[i]-'a']++, pmap[p[i]-'a']++;
        int i=0;
        for(i=0;i<n-m;i++){
            if(check(smap, pmap))
                ans.push_back(i);
            smap[s[i]-'a']--;
            smap[s[i+m]-'a']++;
        }
        if(check(smap, pmap))
            ans.push_back(i);
        return ans;
    }
};