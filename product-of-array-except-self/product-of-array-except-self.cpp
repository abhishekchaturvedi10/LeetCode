class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a;
        vector<int> b(nums.size());
        vector<int> ans;
        int i=1;
        for(int j:nums)
            i*=j, a.push_back(i);
        i=1;
        for(int j=nums.size()-1;j>=0;j--)
            i*=nums[j], b[j]=i;
        ans.push_back(b[1]);
        for(int i=1;i<nums.size()-1;i++)
            ans.push_back(a[i-1]*b[i+1]);
        ans.push_back(a[nums.size()-2]);
        return ans;
    }
};
