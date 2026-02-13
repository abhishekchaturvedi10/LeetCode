class Solution {
public:
    vector<string> res;
    void rec(int open, int close, int openedSoFar, string& cur) {
        if(open==0&&close==0) {
            res.push_back(cur);
            return;
        }
        if(open>0) {
            cur+='(';
            rec(open-1,close,openedSoFar+1,cur);
            cur.pop_back();
        }
        if(openedSoFar>0&&close>0) {
            cur+=')';
            rec(open,close-1,openedSoFar-1,cur);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur="";
        rec(n,n,0,cur);
        return res;
    }
};