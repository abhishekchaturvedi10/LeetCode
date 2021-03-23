class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int cnt = 0;
        while(s.size() <= b.size()) {
            s += a, cnt++;
            if(s.find(b) != -1) 
                return cnt;
        }
        s += a;
        return s.find(b) != -1 ? cnt + 1 : -1;
    }
};