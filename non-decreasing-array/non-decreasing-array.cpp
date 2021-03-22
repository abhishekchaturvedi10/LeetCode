class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag=0, n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                if(flag)
                    return false;
                flag++;
                if(i>0){
                    if(nums[i+1]>=nums[i-1]){
                        nums[i]=nums[i+1];
                    }
                    else{
                        nums[i+1]=nums[i];
                    }
                }
                else{
                    nums[i]=nums[i+1];
                }
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<nums[i]<<" ";
        for(int i=0;i<n-1;i++)
            if(nums[i]>nums[i+1])
                return false;
        return true;
    }
};