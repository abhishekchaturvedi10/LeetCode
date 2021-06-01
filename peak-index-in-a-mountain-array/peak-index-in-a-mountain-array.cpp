class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l=0, r=arr.size()-1;
        
        while(r>l){
            
            int m=l+(r-l)/2;
                        
            if(m>0&&m<arr.size()-1&&(arr[m-1]<arr[m]&&arr[m]>arr[m+1]))
                return m;
            
            if(arr[r]<arr[m]){
                if(m==0||(m>0&&arr[m]>arr[m-1]))
                    l=m+1;
                else
                    r=m;
            }
            else
                l=m+1;
        }
        
        return l;
    }
};