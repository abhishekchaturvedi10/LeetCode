class Solution {
public:
    int maximumSum(vector<int>& arr) {
       
        int n=arr.size();
        
        vector<int> f(n,0), b(n,0);
        
        int cm=arr[0], msf1=arr[0], msf2=arr[n-1];
        
        b[n-1]=arr[n-1];
        
        f[0]=cm;
        
        for(int i=1;i<n;i++) {
            
            cm=max(arr[i], cm+arr[i]);
            
            msf1=max(msf1, cm);
            
            f[i]=cm;
        }
        
        cm=arr[n-1];
        
        for(int i=n-2;i>=0;i--) {
            
            cm=max(arr[i], cm+arr[i]);
            
            msf2=max(msf2, cm);
            
            b[i]=cm;
        }
        
        int res=max(msf1, msf2);
        
        for(int i=1;i<n-1;i++) 
            res=max(res, f[i-1]+b[i+1]);
        
        return res;
    }
};