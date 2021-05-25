class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int res=0, n=arr.size();
        
        for(int i=0;i<n-1;i++){
            int x=0;
            for(int j=i+1;j<n;j++){
                x^=arr[j-1];
                int y=0;
                for(int k=j;k<n;k++){
                    y^=arr[k];
                    if(x==y)                        
                        res++;
                }
            }
        }
        
        return res;
    }
};