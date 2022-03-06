class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int res=0, i=0;
        for(;i<n-2;i++){
            int d=nums[i+1]-nums[i];
            for(int j=2;i+j<n;j++){
                if(d==nums[i+j]-nums[i+j-1]){
                    res++;
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};