class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st="";
        for(char& c:s) {
            st.push_back(c);
            if(st.size()<part.size()) {
                continue;
            }
            if(part==st.substr(st.size()-part.size())) {
                st = st.substr(0,st.size()-part.size());
            }
        }
        return st;
    }
};