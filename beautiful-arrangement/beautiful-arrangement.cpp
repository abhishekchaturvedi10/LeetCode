class Solution {
public:
    
    int res;
    
    void rec(int i, int n, vector<int> &nums){
        
        if(i==n+1){
            res++;
            return;
        }
        
        for(int j=i;j<=n;j++){
                        
            if(nums[j]%i&&i%nums[j])
                continue;
            
            swap(nums[i],nums[j]);
                
            rec(i+1,n,nums);
                
            swap(nums[i],nums[j]);
        }  
    }
    
    int countArrangement(int n) {
        
        vector<int> nums;
        
        for(int i=0;i<=n;i++)
            nums.push_back(i);
        
        res=0;
        
        rec(1,n,nums);
        
        return res;
    }
};