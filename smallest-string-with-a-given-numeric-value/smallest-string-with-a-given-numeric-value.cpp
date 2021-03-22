class Solution {
public:
    string getSmallestString(int n, int k) {
        string res="";
        for(int i=1;i<=n;i++){
            if(k-1>26*(n-i)){
                res+='a'+k-26*(n-i)-1;
                k-=k-26*(n-i);
            }
            else{
                res+='a';
                k--;
            }
        }
        return res;
    }
};