class Solution {
public:
    int minSwaps(string s) {
        
        int n=s.size();
        
        int cnt=0;
        
        for(char i:s)
            if(i=='0')
                cnt++;
        
        if(n%2==0&&n-cnt!=cnt)
            return -1;
        
        if(n&1&&max(n-cnt,cnt)!=min(cnt,n-cnt)+1)
            return -1;
        
        if(n&1){
            
            int res=0;
            
            if(cnt>n-cnt){
                for(int i=0;i<n;i+=2)
                    if(s[i]!='0')
                       res++;
            }
            else{
                for(int i=0;i<n;i+=2)
                    if(s[i]!='1')
                       res++;
            }
            
            return res;
        }
        
        int res0=0,res1=0;
        
        for(int i=0;i<n;i+=2){
            
            if(s[i]!='0')
                res0++;
            
            if(s[i]!='1')
                res1++;
        }
        
        return min(res0,res1);
    }
};