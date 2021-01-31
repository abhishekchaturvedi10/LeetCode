class Solution {
public:
    map<char, int> freq;
    int helper(string s, int start, int end, int k){
        if(end-start<k)
            return 0;
        map<char, int> freq;
        for(int i=start;i<end;i++)
            freq[s[i]]++;
        for(int i=start;i<end;i++){
            if(freq[s[i]]<k){
                int j=i+1;
                while(j<end&&freq[s[j]]<k)
                    j++;
                return max(helper(s, start, i, k), helper(s, j, end, k));
            }
        }
        return end-start;
    }
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }
};