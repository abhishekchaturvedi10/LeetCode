class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1000000,ans=INT_MAX;
        while(r>=l){
            int mid=(l+r)/2,val=0;
            for(int i=0;i<nums.size();i++){
                val+=nums[i]/mid;
                if(nums[i]%mid)
                    val++;
            }
            if(val>threshold)
                l=mid+1;
            else{
                ans=min(ans,mid);
                r=mid-1;
            }
        }
        return ans;
    }
};
