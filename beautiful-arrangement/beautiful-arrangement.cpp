class Solution {
public:
    
    int rec(int i, int n, vector<int> &nums){
        
        if(i==n){
            
            for(int i=1;i<=n;i++)
                if(nums[i]%i&&i%nums[i])
                    return 0;
            
            return 1;
        }
        
        int x=0;
        
        for(int j=i;j<=n;j++){
                
                swap(nums[i],nums[j]);
                
                if(nums[i]%i==0||i%nums[i]==0)
                    x+=rec(i+1,n,nums);
                
                swap(nums[i],nums[j]);
        }  
        
        return x;
    }
    
    int countArrangement(int n) {
        
        vector<int> nums;
        
        for(int i=0;i<=n;i++)
            nums.push_back(i);
        
        return rec(1,n,nums);
    }
};