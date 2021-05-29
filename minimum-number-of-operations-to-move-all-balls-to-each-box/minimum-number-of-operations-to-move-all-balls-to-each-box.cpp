class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        
        vector<int> res(n);
        
        int sum=0, have=boxes[0]-'0';
        
        for(int i=1;i<n;i++){
            
            sum+=have;
            res[i]=sum;
            have+=boxes[i]-'0';
        }
        
        have=boxes[n-1]-'0';
        sum=0;
        
        for(int i=n-2;i>=0;i--){
            
            sum+=have;
            res[i]+=sum;
            have+=boxes[i]-'0';
        }
        
        return res;
    }
};