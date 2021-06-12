class Solution {
public:
    
    const int mod=1000000007; 
    
    long long int power(long long int x, long long int y) { if (y == 0) return 1; long long int p = power(x, y / 2) % mod; p = (p% mod * p% mod) % mod; return (y % 2 == 0) ? p% mod : (x% mod * p% mod) % mod;}
    
    int numSubseq(vector<int>& A, int target) {
                
        sort(A.begin(),A.end());
        
        long long int res=0;
        
        for(int j=0;j<A.size();j++){
            
            int i = upper_bound(A.begin(),A.end(),target-A[j])-A.begin();
            
            i--;
                        
            if(i>=j){
                res+=((long long int)(power(2,i-j))%1000000007);
                res%=1000000007;
            }
            else
                break;
        }
        
        return res;
    }
};