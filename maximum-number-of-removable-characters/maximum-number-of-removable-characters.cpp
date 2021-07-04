class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int l=0, r=removable.size();
        
        while(r>=l) {
                        
            int m=(r+l)/2;
            
            string x=s;
            
            for(int i=0;i<m;i++)
                x[removable[i]]='*';
            
            int i=0,j=0;
            
            while(i<x.size()&&j<p.size()) {
                if(x[i]==p[j]) 
                    j++;
                i++;
            }
            
            if(j==p.size()) 
                l=m+1;
            else
                r=m-1;
        }
        
        return r;
    }
};