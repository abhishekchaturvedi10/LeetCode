class Solution {
public:
    
    int minimumSwap(string s1, string s2) {
        
        if(s1.size()!=s2.size())
            return -1;
                
        int x=0,y=0;
        
        for(char& c:s1) {
            if(c=='x')
                x++;
            else
                y++;
        }
        
        for(char& c:s2) {
            if(c=='x')
                x++;
            else
                y++;
        }
        
        if(x%2||y%2)
            return -1;
        
        int i,res=0,n=s1.size(),xy=0,yx=0;
        
        for(i=0;i<n;i++) {
            if(s1[i]=='x'&&s2[i]=='y')
                xy++;
            if(s1[i]=='y'&&s2[i]=='x')
                yx++;
        }
        
        res+=xy/2+yx/2;
        
        if(xy&1)
            res+=2;
        
        return res;
    }
};