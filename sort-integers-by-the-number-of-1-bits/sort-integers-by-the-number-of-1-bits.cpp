class Solution {
public:
    
    static bool comp(int a, int b){
        
        if(a==b)
            return 0;
        
        int cnt1=0, cnt2=0, c=a, d=b;
        
        while(a){
            cnt1+=a&1;
            a>>=1;
        }
        
        while(b){
            cnt2+=b&1;
            b>>=1;
        }
        
        if(cnt1==cnt2)
            return c<d;
        
        return cnt1<cnt2;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), comp);
        
        return arr;
        
    }
};