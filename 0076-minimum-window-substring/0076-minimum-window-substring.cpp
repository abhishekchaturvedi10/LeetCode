class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> freq;

        // Populate frequency map with characters from t
        for (char c : t)
            freq[c]++;

        int l = 0, r = 0, res = INT_MAX, si = -1;
        int required = t.size(); // Total characters from t that need to be matched

        while (r < s.size()) {
            // If character at 'r' is in 't', decrease its count and adjust required
            if (freq[s[r]] > 0) {
                required--;
            }
            freq[s[r]]--; // Decrease the count for the character at 'r'

            // Shrink the window from the left if all characters are satisfied
            while (required == 0) {
                if (r - l + 1 < res) {
                    res = r - l + 1;
                    si = l;
                }

                // Prepare to remove the character at 'l' and update required
                freq[s[l]]++;
                if (freq[s[l]] > 0) {
                    required++;
                }
                l++;
            }
            r++;
        }

        return si == -1 ? "" : s.substr(si, res);
    }
};