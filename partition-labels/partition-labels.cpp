class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, vector<int>> m;
        for(int i=0;i<s.size();i++)
            m[s[i]].push_back(i);
        int prev=0, cur=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(m[s[i]][0]>cur){
                //cout<<s[i]<<" ";
                ans.push_back(cur-prev+1);
                cur=m[s[i]][m[s[i]].size()-1];
                prev=i;
            }
            else{
                cur=max(cur, m[s[i]][m[s[i]].size()-1]);
            }
            //cout<<i<<" "<<prev<<" "<<cur<<endl;
        }
        ans.push_back(cur-prev+1);
        return ans;
    }
};