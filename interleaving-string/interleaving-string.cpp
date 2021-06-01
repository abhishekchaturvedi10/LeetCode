class Solution {
public:
    
    int dp[105][105];
    
    bool rec(int s1, int s2, string a, string b, string c, string d){
        
        if(s1==a.size()&&s2==b.size()){
            
            cout<<c<<" "<<d<<'\n';
            
            if(c==d)
                return 1;
            
            return 0;
        }
            
        if(dp[s1][s2]!=-1)
            return dp[s1][s2];
        
        int res=0;
        
        if(s1==a.size()&&b[s2]==c[d.size()])
            res=res||rec(s1,s2+1,a,b,c,d+b[s2]);
        else if(s2==b.size()&&a[s1]==c[d.size()])
            res=res||rec(s1+1,s2,a,b,c,d+a[s1]);
        else{
            if(a[s1]==c[d.size()])
                res=res||(rec(s1+1,s2,a,b,c,d+a[s1]));
            if(b[s2]==c[d.size()])              
                res=res||rec(s1,s2+1,a,b,c,d+b[s2]);
        }
        
        return dp[s1][s2]=res;
        
    }
    
    bool isInterleave(string A, string B, string C) {
        
        if(C.size()!=A.size()+B.size())
            return 0;
            
        memset(dp,-1,sizeof(dp));
        
        return rec(0,0,A,B,C,"");
    }
};