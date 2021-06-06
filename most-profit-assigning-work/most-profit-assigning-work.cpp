class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        
        int n=p.size();
        
        vector<vector<int>> v(n);
        
        for(int i=0;i<n;i++)
            v[i]={d[i],p[i]};
        
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        
        int i=0, j=0, res=0, maxp=0;
        
        while(i<n&&j<w.size()){
                    
            if(v[i][0]>w[j]){
                res+=maxp;
                j++;
                continue;
            }
            
            if(v[i][0]<=w[j]){
                maxp=max(maxp,v[i][1]);
                i++;
            }
        }
        
        while(j<w.size()){
            res+=maxp;
            j++;
        }
        
        return res;
    }
};