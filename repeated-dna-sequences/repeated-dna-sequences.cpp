class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;
        if(s.size()<10)
            return {};
        vector<string> ans;
        string x = s.substr(0, 10);
        m[x]++;
        for(int i=0;i+10<s.size();i++){
            x.erase(0, 1);
            x+=s[i+10];
            if(m[x]==1)
                ans.push_back(x);
            m[x]++;
        }
        return ans;
    }
};