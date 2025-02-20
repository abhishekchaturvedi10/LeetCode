class Solution {
public:
    map<pair<string,int>,string> seen;
    unordered_map<string,int> seen1;
    string res;
    string rec(int i, int n, string cur) {
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
        string x = rec(i+1,n,cur+"0");
        if(x!="") {
            return seen[{cur,i}]=x;
        }
        string y = rec(i+1,n,cur+"1");
        return seen[{cur,i}]=y;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        for(string s:nums) {
            seen1[s]=1;
        }
        res="";
        return rec(0, nums.size(), "");
    }
};