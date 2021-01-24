class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i && nums[i]==nums[i-1])
                continue;
            int l=i+1,r=n-1;
            while(r>l){
                int s=nums[i]+nums[l]+nums[r];
                if(s<0)
                    l++;
                else if(s>0)
                    r--;
                else{
                    vector<int> a={nums[i],nums[l],nums[r]};
                    ans.push_back(a);
                    while(l<n-1 && nums[l]==nums[l+1])
                        l++;
                    while(r>0 && nums[r]==nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};
