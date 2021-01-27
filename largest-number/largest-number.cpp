class Comparator{
public:
    bool operator()(const string &sa, const string &sb) const{
        return (sa+sb < sb+sa);
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(int i:nums)
            a.push_back(to_string(i));
        sort(a.begin(),a.end(),Comparator());
        reverse(a.begin(),a.end());
        string ans="";
        for(auto i:a)
            ans+=i;
        if(ans[0] == '0'){
            ans.clear();
            ans = "0";
        }
        return ans;
    }
};
