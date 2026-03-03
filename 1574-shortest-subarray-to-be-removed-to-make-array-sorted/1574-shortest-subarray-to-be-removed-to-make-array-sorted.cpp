class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n=arr.size(), l, r;
        
        for(l=0;l<n-1;l++) {
            if(arr[l]>arr[l+1]) {
                break;
            }
        }
        if(l==n-1) {
            return 0;
        }

        for(r=n-1;r>=1;r--) {
            if(arr[r-1]>arr[r]) {
                break;
            }
        }
      
        int res=min(n-l-1,r), i=0, j=r;

        while(i<=l&&j<n) {
            if(arr[i]<=arr[j]) {
                res=min(res,j-i-1);
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};