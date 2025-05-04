class Solution {
private:
    int countPairs(int x) {
        int count=0;
        count+=x*(x-1);
        count/=2;
        return count;
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(auto& v: dominoes) {
            if(v[0]>v[1]) {
                int x=v[0];
                v[0]=v[1];
                v[1]=x;
            }
        }
        sort(dominoes.begin(),dominoes.end());
        int res=0, curCnt=1;
        for(int i=1;i<dominoes.size();i++) {
            if(dominoes[i][0]==dominoes[i-1][0] && dominoes[i][1]==dominoes[i-1][1]) {
                curCnt++;
            } else {
                if(curCnt>1) {
                    res+=countPairs(curCnt);
                    curCnt=1;
                }
            }
        }
        if(curCnt>1) {
            cout<<curCnt<<endl;
            res+=countPairs(curCnt);
        }
        return res;
    }
};