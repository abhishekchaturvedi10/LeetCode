class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++) {
            int x=nums[i], sum=0;
            while(x>0) {
                sum+=x%10;
                x/=10;
            }
            if(mpp.find(sum)==mpp.end()) {
                mpp[sum]={nums[i]};
            } else {
                mpp[sum].push_back(nums[i]);
            }
        }
        int res=-1;
        for(auto& p:mpp) {
            vector<int> ints = p.second;
            int sz=ints.size();
            if(sz>1) {
                sort(ints.begin(),ints.end());
                res=max(res,ints[sz-1]+ints[sz-2]);
            }
        }
        return res;
    }
};