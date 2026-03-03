class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size(), l;
        for(l=0;l<n-1;l++) {
            if(arr[l]>arr[l+1]) {
                break;
            }
        }
        if(l==n-1) {
            return 0;
        }
        int r;
        for(r=n-1;r>=1;r--) {
            if(arr[r-1]>arr[r]) {
                break;
            }
        }
        // if(r==0) {
        //     return n-1;
        // }
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
        
        // int lp=l, rp=r, res=INT_MAX;
        // if(lp>0&&rp<n-1&&arr[lp-1]<=arr[rp+1]) {
        //     res=min(res,rp-lp+1);
        // }
        // cout<<lp<<" ++ "<<rp<<endl;
        // while(lp>=0&&arr[lp]>arr[rp]) {
        //     lp--;
        // }
        // cout<<lp<<" -- "<<rp<<endl;
        // res=min(rp-lp-1,res);
        // lp=l;
        // while(rp<n&&arr[lp]>arr[rp]) {
        //     rp++;
        // }
        // cout<<lp<<" ~~ "<<rp<<endl;

        // return min(res,rp-lp-1);
    }
};