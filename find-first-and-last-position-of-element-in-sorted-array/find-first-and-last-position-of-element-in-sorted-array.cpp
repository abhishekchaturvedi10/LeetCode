class Solution {
public:
    vector<int> ans{INT_MAX, -1};
    void bs1(vector<int>& nums, int target, int l, int r){
        while(r>=l){
            int m=(l+r)/2;
            if(nums[m]==target){
                ans[0]=min(ans[0], m);
                r=m-1;
            }
            else if(nums[m]>target)
                r=m-1;
            else
                l=m+1;
        }
    }
    void bs2(vector<int>& nums, int target, int l, int r){
        while(r>=l){
            int m=(l+r)/2;
            //cout<<l<<" "<<r<<" "<<m<<endl;
            if(nums[m]==target){
                ans[1]=max(ans[1], m);
                l=m+1;
            }
            else if(nums[m]>target)
                r=m-1;
            else
                l=m+1;
            //cout<<l<<" "<<r<<" "<<endl;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            ans[0]=-1;
            return ans;
        }
        if(nums.size()==1){
            if(nums[0]==target){
                ans[0]=0;
                ans[1]=0;
            }
            else
                ans[0]=-1;
            return ans;
        }
        bs1(nums, target, 0, nums.size()-1);
        bs2(nums, target, 0, nums.size()-1);
        if(ans[0]==INT_MAX)
            ans[0]=-1;
        return ans;
    }
};