class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> leftMax(n), rightMin(n);

        for(int i=0;i<n;i++) {
            if(i==0) {
                leftMax[0]=nums[0];
            } else {
                leftMax[i]=max(nums[i],leftMax[i-1]);
            }
        }

        for(int i=n-1;i>=0;i--) {
            if(i==n-1) {
                rightMin[n-1]=nums[n-1];
            } else {
                rightMin[i]=min(nums[i],rightMin[i+1]);
            }
        }
        
        for(int i=0;i<n-1;i++) {
            if(leftMax[i]<=rightMin[i+1]) {
                return i+1;
            }
        }

        return n;
    }
};