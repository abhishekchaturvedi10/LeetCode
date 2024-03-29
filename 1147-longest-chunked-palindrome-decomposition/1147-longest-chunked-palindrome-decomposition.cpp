class Solution {
public:
    
    int dp[1005][1005];
    
    int rec(string& text, int i, int j) {
                
        if(i>j)
            return 0;
        
        if(text.size()%2==0) {
              if(i==(text.size()-1)/2) {
                  if(text[i]==text[i+1])
                      return dp[i][j]=2;
                  else
                      return dp[i][j]=1;
              }  
              else if(i>(text.size()-1)/2)
                  return 1;   
        } 
        else 
            if(i>=(text.size()-1)/2)
                return 1;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        if(text[i]==text[j])
            return dp[i][j]=2+rec(text,i+1,j-1);
        else {
            
            string x,y;
            
            for(int ii=i;ii<=(text.size()-1)/2;ii++) {
                
                x+=text[ii];
                y+=text[j-(ii-i)];
                string yy=y;
                
                reverse(yy.begin(),yy.end());
                
                if(yy==x)
                    dp[i][j]=max(dp[i][j],2+rec(text,ii+1,j-(ii-i)-1));
            }   
            
            
            return dp[i][j]=max(dp[i][j],1);
        }
    }
    
    int longestDecomposition(string& S) {
        
        int res = 0, n = S.length();
        
        string l = "", r = "";
        
        for (int i = 0; i < n; ++i) {
            
            l = l + S[i], r = S[n - i - 1] + r;
            
            if (l == r)
                ++res, l = "", r = "";
        }
        
        return res;
    }
};