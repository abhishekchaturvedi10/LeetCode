class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int res=0;
        
        while(arr.size()>1){
            
            int mini=INT_MAX, ind;
            
            for(int i=0;i<arr.size()-1;i++){
                if(arr[i]*arr[i+1]<mini){
                    mini=arr[i]*arr[i+1];
                    ind=i;
                }
            }
            
            res+=mini;
            
            if(arr[ind] > arr[ind+1]) {
                ind += 1;
            }
            
            arr.erase(arr.begin()+ind);
        }
        
        return res;
    }      
};