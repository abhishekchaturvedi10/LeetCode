class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, res=0, mf=0;
        unordered_map<char,int> m;
        while(r<s.size()) {
            m[s[r]]++;
            mf=max(mf,m[s[r]]);
            while((r-l+1)-mf>k) {
                m[s[l++]]--;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};