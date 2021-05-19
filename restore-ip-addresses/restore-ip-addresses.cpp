class Solution {
public:
    
    vector<string> res;

    void rec(int i, string &s, string &cur, int val, int len) {

        if (i == -1) {
            
            if(cur[0]=='0'&&cur[1]!='.')
                return;

            int f = 1;

            int cnt = 0;

            if (cur[0] == '.')
                cnt++;

            for (int i = 1; i < cur.size(); i++) {
                if (cur[i] == '0' && cur[i - 1] == '.') {
                    if (i + 1 < cur.size() && cur[i + 1] != '.') {
                        f = 0;
                    }
                }
                if (cur[i] == '.')
                    cnt++;
            }

            if (f && cnt == 3) 
                res.push_back(cur);

            return;
        }

        string cc = "";
        cc += s[i];
        cc += '.';
        cc += cur;
        rec(i - 1, s, cc, s[i] - '0', 1);

        int x = val + (int)pow(10, len) * (s[i] - '0');

        if (x < 256) {
            string cc;
            cc += s[i];
            cc += cur;
            rec(i - 1, s, cc, x, len + 1);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        if(s=="")
            return res;
        
        if(s.size()>12)
            return res;
        
        string x;

        x += s[s.size() - 1];

        rec(s.size() - 2, s, x, s[s.size() - 1] - '0', 1);

        return res;
    }
};