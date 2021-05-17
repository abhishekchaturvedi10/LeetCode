class Solution {
public:
    int minDays(vector<int>& a, int n, int k) {
        
        if(k*n>a.size())
            return -1;
        
        int l=INT_MAX, r=INT_MIN;
        
        for(int &i:a){
            l=min(l,i);
            r=max(r,i);
        }
        
        int res=INT_MAX;
        
        while(r>=l){
            
            int m=l+(r-l)/2;
                        
            int result=0,count=0;
            
            for(int i=0;i<a.size();i++){
                
                if(a[i]<=m)
                    count++;
                else
                    count=0;
                
                if(count==k)    
                    result++,count=0;
            }
            
            if(result>=n){
                r=m-1;
                res=min(res,m);
            }
            else{
                l=m+1;
            }
        }
        
        return res;
    }
};