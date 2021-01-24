class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k>0){
            vector<int> a;
            for(int i=nums.size()-k;i<nums.size();i++)
                a.push_back(nums[i]);
            for(int i=0;i<k;i++){
                if(a.size()<nums.size())
                    a.push_back(nums[i]);
            }
            if(a.size()<nums.size()){
                for(int i=k;i<nums.size()-k;i++)
                    a.push_back(nums[i]);
            }
            nums=a;
        }
    }
};
