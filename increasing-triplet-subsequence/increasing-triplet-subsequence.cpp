class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> mintillhere(n);
        vector<int> maxtillhere(n);
        //map<int, int> minpos, maxpos;
        for(int i=0;i<n;i++){
            // if(!minpos[nums[i]])
            //     minpos[nums[i]]=i;
            if(!i)
                mintillhere[i]=nums[i];
            else
                mintillhere[i]=min(nums[i], mintillhere[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            // if(!maxpos[nums[i]])
            //     maxpos[nums[i]]=i;
            if(i==n-1)
                maxtillhere[i]=nums[i];
            else
                maxtillhere[i]=max(nums[i], maxtillhere[i+1]);
        }
        for(int i=1;i<n-1;i++){
            if(mintillhere[i]<nums[i]&&maxtillhere[i]>nums[i])
                return true;
        }
        return false;
    }
};