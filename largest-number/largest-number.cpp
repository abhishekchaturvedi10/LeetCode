class Comparator{
public:
    bool operator()(string sa, string sb) {
        return (sa+sb > sb+sa);
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(int i:nums)
            a.push_back(to_string(i));
        sort(a.begin(),a.end(),Comparator());
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
