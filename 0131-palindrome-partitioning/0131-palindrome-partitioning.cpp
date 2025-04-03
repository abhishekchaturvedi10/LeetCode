class Solution {
public:
    
    vector<vector<string>> res;
    
    bool isPalindrome(string s){
        for(int i=0;i<(s.size()+1)/2;i++)
            if(s[i]!=s[s.size()-1-i])
                return 0;
        return 1;
    }
    
    void rec(string& s, int i, string& cur, vector<string>& v){  
        if(i==s.size()){
            if(isPalindrome(cur)){
                v.push_back(cur);
                res.push_back(v);
                v.pop_back();
            } 
            return;
        }
        if(cur.size()>0&&isPalindrome(cur)){
            v.push_back(cur);
            string x;
            rec(s,i,x,v);
            v.pop_back();
        }
        string x=cur+s[i];
        rec(s,i+1,x,v);
    }
    
    vector<vector<string>> partition(string s) {
        string x;
        vector<string> v;
        rec(s,0,x,v);
        return res;
    }
};