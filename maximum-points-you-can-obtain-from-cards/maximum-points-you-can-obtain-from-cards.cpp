class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
                
        int res=0;
        
        for(int i=0;i<k;i++)
            res+=cardPoints[i];
        
        int temp=res, n=cardPoints.size();
        
        for(int i=n-1;i>=n-k;i--){
            
            temp+=cardPoints[i];
            temp-=cardPoints[k-n+i];
            
            res=max(res,temp);
        }
        
        return res;
    }
};