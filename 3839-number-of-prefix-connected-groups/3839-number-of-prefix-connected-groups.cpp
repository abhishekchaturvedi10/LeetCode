class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        map<string,int> mp;
        int res=0;

        for(string word:words) {
            if(word.size()<k) {
                continue;
            }
            string prefix = word.substr(0,k);
            mp[prefix]++;
            if(mp[prefix]==2) {
                res++;
            }
        }

        return res;
    }
};