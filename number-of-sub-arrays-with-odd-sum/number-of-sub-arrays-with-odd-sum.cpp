class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int sum=0, odd=0, even=0;
        
        long long int res=0;
        
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
            
            if(sum&1)
                res+=(1+even);
            else
                res+=odd;
    
            if(sum&1)
                odd++;
            else
                even++;
            
            // cout<<i<<" "<<res<<"\n";
        }
        
        return res%1000000007;
    }
};