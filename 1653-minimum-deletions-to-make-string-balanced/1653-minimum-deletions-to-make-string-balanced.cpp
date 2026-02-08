class Solution {
public:
    int minimumDeletions(string& s) {
        int res=0, aCnt=0, bCnt=0;
        for(char c:s) {
            if(c=='a') {
                if(bCnt>0) {
                    res++;
                    bCnt--;
                }
                aCnt++;
            } else {
                bCnt++;
            }
        }
        return res;
    }
};