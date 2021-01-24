class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for(string i:strs){
            string j=i;
            sort(j.begin(),j.end());
            m[j].push_back(i);
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
