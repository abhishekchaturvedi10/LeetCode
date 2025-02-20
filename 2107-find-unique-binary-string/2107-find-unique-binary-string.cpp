class Solution {
public:
    map<pair<string,int>,string> seen;
    unordered_map<string,int> seen1;
    string rec(int i, int n, string& cur) {
        if(i>n) {
            return "";
        }
        if(i==n) {
            if(seen1.find(cur)!=seen1.end() ) {
                return "";
            } else {
                return cur;
            }
        }
        if(seen.find({cur,i})!=seen.end()) {
            return seen[{cur,i}];
        }
        string cur1=cur+"0";
        string x = rec(i+1,n,cur1);
        if(x!="") {
            return seen[{cur,i}]=x;
        }
        cur1=cur+"1";
        string y = rec(i+1,n,cur1);
        return seen[{cur,i}]=y;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        for(string& s:nums) {
            seen1[s]=1;
        }
        string cur="";
        return rec(0, nums.size(), cur);
    }
};