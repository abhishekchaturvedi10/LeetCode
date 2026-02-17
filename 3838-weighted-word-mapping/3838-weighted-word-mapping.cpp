class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ss = "abcdefghijklmnopqrstuvwxyz";
        reverse(ss.begin(),ss.end());

        string res="";

        for(string word: words) {
            int s = 0;
            for(char c:word) {
                s+=weights[c-'a'];
            }
            res+=ss[s%26];
        }

        return res;
    }
};