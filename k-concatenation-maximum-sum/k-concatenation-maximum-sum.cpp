class Solution {
public:
    int kConcatenationMaxSum(vector<int>& A, int k) {
        
        long long a=0, m=0, s=0; 
        int n=A.size();
        
        for(int i=0;i<n*(min(2,k));i++) {
            
            s=max((long long)A[i%n], s+A[i%n]);
            
            m=max(s,m);
            
            if(i<n)
                a+=A[i];
        }
                
        while(a>0&&k-->2) 
            m+=a, m%=1000000007;
        
        return m%1000000007;
    }
};