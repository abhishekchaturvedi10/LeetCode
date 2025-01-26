class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int l=0, r=0, res=0;
        unordered_set<char> st;
        while(r<s.size()) {
            if(st.contains(s[r])) {
                st.erase(s[l]);
                l++;
            } else {
                res=max(res,r-l+1);
                st.insert(s[r]);
                r++;
            }
        }
        return res;
    }
};