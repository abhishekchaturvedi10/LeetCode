class Solution {
public:
    
    int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
    {   
        if (arr1 == end1)
            return arr2[k];

        if (arr2 == end2)
            return arr1[k];

        int mid1 = (end1 - arr1) / 2;
        int mid2 = (end2 - arr2) / 2;
        
        if (mid1 + mid2 < k) {

            if (arr1[mid1] > arr2[mid2])
                return kth(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1);
            
            return kth(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1);
        }
        else {

            if (arr1[mid1] > arr2[mid2])
                return kth(arr1, arr2, arr1 + mid1, end2, k);
            
            return kth(arr1, arr2, end1, arr2 + mid2, k);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size(), n=nums2.size();
        
        if(m==0){
            if(n&1)
                return nums2[n/2];
            return ((double)(nums2[n/2]+nums2[n/2-1]))/2;
        }
        
        if(n==0){
            if(m&1)
                return nums1[m/2];
            return ((double)(nums1[m/2]+nums1[m/2-1]))/2;
        }
        
        int a[m], b[n];
        
        for(int i=0;i<m;i++)
            a[i]=nums1[i];
        
        for(int i=0;i<n;i++)
            b[i]=nums2[i];
        
        
        if((m+n)&1)
            return kth(a,b,a+nums1.size(),b+nums2.size(),(nums1.size()+nums2.size())/2);
        
        return ((double)kth(a,b,a+nums1.size(),b+nums2.size(),(nums1.size()+nums2.size())/2)+(double)kth(a,b,a+nums1.size(),b+nums2.size(),(nums1.size()+nums2.size())/2-1))/2;
    }
};