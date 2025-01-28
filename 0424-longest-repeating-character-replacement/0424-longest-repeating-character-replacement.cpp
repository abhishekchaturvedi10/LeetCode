class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, res=0, mf=0;
        unordered_map<char,int> m;
        m[s[0]]++;
        while(r<s.size()) {
            mf=max(mf,m[s[r]]);
            if((r-l+1)-mf<=k) {
                res=max(res,r-l+1);
                m[s[++r]]++;
            } else {
                m[s[l++]]--;
            }
        }
        return res;
    }
};