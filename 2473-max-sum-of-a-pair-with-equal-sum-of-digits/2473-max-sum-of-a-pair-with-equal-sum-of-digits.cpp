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
                mpp[sum]={i};
            } else {
                mpp[sum].push_back(i);
            }
        }
        int res=-1;
        for(auto p:mpp) {
            vector<int> indices = p.second;
            int sz=indices.size();
            for(int i=0;i<sz;i++) {
                for(int j=i+1;j<sz;j++) {
                    res=max(res,nums[indices[i]]+nums[indices[j]]);
                }
            }
        }
        return res;
    }
};