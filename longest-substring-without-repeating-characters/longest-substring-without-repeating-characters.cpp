class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int i=0, ans=1, j=0;
        map<char, int> seen;
        while(i<s.size()&&j<s.size()){
            while(j<s.size()&&!seen[s[j]]){
                seen[s[j]]++;
                j++;
            }
            ans=max(ans, j-i);
            seen[s[i]]=0;
            i++;
            //seen.clear();
        }
        return ans;
    }
};