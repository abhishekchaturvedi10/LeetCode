class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum=0, mn=INT_MAX;
        
        for(int &i:nums){
            sum+=i;
            mn=min(mn,i);
        }
        
        return sum-mn*(nums.size());
    }
};