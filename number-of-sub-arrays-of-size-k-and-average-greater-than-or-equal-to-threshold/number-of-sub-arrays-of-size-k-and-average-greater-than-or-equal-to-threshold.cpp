class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int i=0, j=0, res=0, s=0;
        
        while(j<k)
            s+=arr[j++];
        
        if(s>=k*threshold)
            res++;
        
        i++;
        
        while(j<arr.size()) {
            
            s-=arr[i++-1];
            s+=arr[j++];
            
            if(s>=k*threshold)
                res++;
        }
        
        return res;
    }
};