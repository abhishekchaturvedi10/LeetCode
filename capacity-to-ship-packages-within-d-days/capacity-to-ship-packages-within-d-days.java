class Solution {
    public int shipWithinDays(int[] weights, int days) {
        
        int l=1,h=0;
        
        for(int i:weights){
            if(i>l)
                l=i;
            h+=i;
        }
        
        int res=h;
        
        while(h>=l){
            
            int m=l+(h-l)/2;
            
            int d=1, s=0;
            
            for(int i:weights){
                
                if(s+i>m){
                    d++;
                    s=i;
                }
                else{
                    s+=i;
                }
            }
            
            if(d>days){
                l=m+1;
            }
            else{
                h=m-1;
                res=m;
            }
        }
        
        return res;
    }
}