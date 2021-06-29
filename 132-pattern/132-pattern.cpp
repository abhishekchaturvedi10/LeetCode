class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int ss=INT_MIN;
        
        stack<int> s;
        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(nums[i]<ss)
                return 1;
            
            while(!s.empty()&&s.top()<nums[i]){
                ss=s.top();
                s.pop();
            }
            
            s.push(nums[i]);
        }
        
        return 0;
    }
};