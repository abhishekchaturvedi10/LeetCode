class Solution {
public:
    int takeCharacters(string& s, int k) {
        
        int aCnt=0, bCnt=0, cCnt=0, mins=0, l=0, r=0, totalACnt=0, totalBCnt=0, totalCCnt=0;

        for(char& c:s) {
            if(c=='a') {
                totalACnt++;
            } else if(c=='b') {
                totalBCnt++;
            } else {
                totalCCnt++;
            }
        }

        if(totalACnt<k || totalBCnt<k || totalCCnt<k) {
            return -1;
        }

        while(r<s.size()) {
            if(s[r]=='a') {
                aCnt++;
            } else if(s[r]=='b') {
                bCnt++;
            } else {
                cCnt++;
            }
            while(l<=r && (totalACnt-aCnt<k || totalBCnt-bCnt<k || totalCCnt-cCnt<k)) {
                if(s[l]=='a') {
                    aCnt--;
                } else if(s[l]=='b') {
                    bCnt--;
                } else {
                    cCnt--;
                }
                l++;
            }
            mins=max(mins,r-l+1);
            r++;
        }

        return s.size()-mins;
    }
};