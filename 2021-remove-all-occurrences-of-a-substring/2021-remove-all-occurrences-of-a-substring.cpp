class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st="";
        int l=part.size();
        for(char& c:s) {
            st.push_back(c);
            if(st.size()>=l&&part==st.substr(st.size()-l)) {
                st.erase(st.size() - l, l);
            }
        }
        return st;
    }
};