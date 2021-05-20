class Solution {
public:
    int findMin(vector<int>& a) {
        
        int n=a.size(),l=0,r=n-1;
                
        while(r>=l){
            
            int m=l+(r-l)/2;
            
            if(m<n-1&&a[m]>a[m+1]){
                return a[m+1];
                break;
            }
            
            if(m>0&&a[m-1]>a[m]){
                return a[m];
            }
            
            if(a[l]>a[m])
                r=m-1;
            else
                l=m+1;
        }
        
        return a[0];
    }
};