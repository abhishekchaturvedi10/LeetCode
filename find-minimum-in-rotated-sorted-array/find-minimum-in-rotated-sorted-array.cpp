class Solution {
public:
    int findMin(vector<int>& a) {
        
        int n=a.size(),l=0,r=n-1;
                
        while(r>l){
            
            int m=l+(r-l)/2;
            
            if(a[r]<a[m])
                l=m+1;
            else
                r=m;
        }
        
        return a[l];
    }
};