class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        long long res=0;
        
        for(int i=0;i<nums1.size();i++)
            res+=abs(nums1[i]-nums2[i]);
        
        vector<int> nums11=nums1;
        
        sort(nums11.begin(), nums11.end());
        
        long long temp=res;
        
        for(int i=0;i<nums1.size();i++) {
            
            auto ind=lower_bound(nums11.begin(),nums11.end(),nums2[i]);
            
            if(ind == nums11.end())
                ind--;
                
            res=min(res, (temp-abs(nums1[i]-nums2[i])+abs(nums2[i]-*(ind))));
                                    
            if(ind!=nums11.begin()) 
                res=min(res, (temp-abs(nums1[i]-nums2[i])+abs(nums2[i]-*prev(ind))));
        }
        
        return res%1000000007;
    }
};