class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(), cnt=0;
        vector<int> freq(26);
        for(int i=0;i<n;i++) {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
            if(s1[i]!=s2[i]) {
                cnt++;
                if(cnt>2) {
                    break;
                }
            }
        }
        for(int i=0;i<26;i++) {
            if(freq[i]!=0) {
                return false;
            }
        }
        return cnt<3;
    }
};