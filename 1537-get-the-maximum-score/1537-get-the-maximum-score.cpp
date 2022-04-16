class Solution {
public:
    
    long long dp[100005][2];
    
    unordered_map<int,int> a,b;
    
    long long rec(int i, int turn, vector<int>& A, vector<int>& B) {
        
        if(turn==0) {
            
            if(i>=A.size())
                return 0;
            
            if(dp[i][turn]!=-1)
                return dp[i][turn];
            
            if(b.find(A[i])!=b.end()) {
                return dp[i][turn]=(max((A[i]+rec(b[A[i]]+1,turn^1,A,B)), (A[i]+rec(i+1,turn,A,B))));
            }
            else {
                return dp[i][turn]=(A[i]+rec(i+1,turn,A,B));
            }
        }
        else {
            
            if(i>=B.size())
                return 0;
            
            if(dp[i][turn]!=-1)
                return dp[i][turn];
            
            if(a.find(B[i])!=a.end()) {
                return dp[i][turn]=(max((B[i]+rec(a[B[i]]+1,turn^1,A,B)), (B[i]+rec(i+1,turn,A,B))));
            }
            else {
                return dp[i][turn]=(B[i]+rec(i+1,turn,A,B));
            }
        }
    }
    
    int maxSum(vector<int>& A, vector<int>& B) {
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<A.size();i++)
            a[A[i]]=i;
        
        for(int i=0;i<B.size();i++) 
            b[B[i]]=i;
        
        return (max(rec(0,0,A,B), rec(0,1,A,B)))%1000000007;
    }
};