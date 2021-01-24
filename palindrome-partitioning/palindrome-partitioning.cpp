class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int low, int high) {
        while (low < high) 
            if (s[low++] != s[high--]) 
                return false;
        return true;
    }
    void helper(vector<string> &a, string s, int i){
        if(i==s.size()){
            ans.push_back(a);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalindrome(s, i, j)){
                a.push_back(s.substr(i, j-i+1));
                helper(a, s, j+1);
                a.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> a;
        helper(a, s, 0);
        return ans;
    }
};
