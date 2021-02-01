class Solution {
public:
    bool isPowerOfTwo (int x){ 
        return x && (!(x&(x-1))); 
    } 
    vector<int> countBits(int num) {
        if(!num)
            return {0};
        vector<int> res(num+1);
        res[1]=1;
        int prev;
        for(int i=2;i<=num;i++){
            if(isPowerOfTwo(i))
                res[i]=1, prev=i;
            else{
                res[i]=res[prev]+res[i-prev];
            }
        }
        return res;
    }
};