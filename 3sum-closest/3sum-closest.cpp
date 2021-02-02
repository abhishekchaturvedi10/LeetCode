class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n&&ans!=0;i++){
            int l=i+1,r=n-1;
            while(r>l){
                int s=nums[i]+nums[l]+nums[r];
                if(abs(target-s)<abs(ans))
                    ans=target-s;
                if(s<target)
                    l++;
                else 
                    r--;
            }
        }
        return target-ans;
    }
};