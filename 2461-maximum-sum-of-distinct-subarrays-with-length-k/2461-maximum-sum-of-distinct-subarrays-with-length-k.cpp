class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long subarraySum=0, res=0;
        int cnt=0;
        unordered_map<int,int> freq;
        
        for(int i=0;i<k;i++) {
            subarraySum+=nums[i];
            freq[nums[i]]++;
            if(freq[nums[i]]==2) {
                cnt++;
            }
        }

        cnt=max(cnt,0);
        if(cnt==0) {
            res=subarraySum;
        }

        int l=1, r=k;
        while(r<nums.size()) {
            cout<<l<<" "<<r<<" "<<subarraySum<<" "<<cnt<<" ";
            subarraySum-=nums[l-1];
            subarraySum+=nums[r];
            freq[nums[l-1]]--;
            if(freq[nums[l-1]]==1) {
                cnt--;
            }
            freq[nums[r]]++;
            if(freq[nums[r]]==2) {
                cnt++;
            }
            cnt=max(cnt,0);
            if(cnt==0) {
                res=max(res,subarraySum);
            }
            r++;
            l++;
        }

        cnt=max(cnt,0);
        if(cnt==0) {
            res=max(res,subarraySum);
        }

        return res;
    }
};