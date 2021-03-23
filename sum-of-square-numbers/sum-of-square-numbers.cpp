class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c>=2147482647)
            return false;
        int x=0;
        map<int, int> m;
        while(x*x<=c){
            m[x*x]=1;
            if(m[c-x*x])
                return true;
            x++;
        }
        return false;
    }
};