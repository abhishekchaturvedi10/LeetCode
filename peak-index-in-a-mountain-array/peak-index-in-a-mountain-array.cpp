class Solution {
public:
    int val=-1,ans;
    void bs(vector<int>& arr, int l, int r, int n){
        if(l>r||l<0||r>=n) return;
        int mid=(l+r)/2;
        if(arr[mid]>val) ans=mid;
        val=max(val,arr[mid]);
        bs(arr, l, mid-1, n);
        bs(arr, mid+1, r, n);
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        bs(arr, 0, arr.size()-1, arr.size());
        return ans;
    }
};
