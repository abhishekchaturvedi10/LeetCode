class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        
        sort(a.begin(),a.end());
        
        int n=a.size();
        
        int l=0, h=a[n-1]-a[0];
        
        while(h>l){
            
            int m=(l+h)/2;
                        
            int j=0, cnt=0;
            
            for(int i=0;i<n;i++){
                                
                while(j<n&&a[j]-a[i]<=m)
                    j++;
                                
                cnt+=j-i-1;
            }
            
            if(cnt<k)
                l=m+1;
            else
                h=m;
        }
        
        return l; 
    }
};