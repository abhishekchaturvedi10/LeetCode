class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        sort(p.begin(),p.end());
        
        int i=0,j=p.size()-1;
        
        int res=0;
        
        while(i<=j){
            
            int s=0,cnt=0;
            
            res++;
            
            while(j>=i&&s+p[j]<=limit&&cnt<2){
                s+=p[j];
                j--;
                cnt++;
            }
            
            while(i<=j&&s+p[i]<=limit&&cnt<2){
                s+=p[i];
                i++;
                cnt++;
            }
            
            s=0;
        }
        
        return res;
    }
};