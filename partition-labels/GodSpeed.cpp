class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]=i;
        int prev=0,cur=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            cur=max(cur, m[s[i]]);
            if(i==cur){
                ans.push_back(i-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};
