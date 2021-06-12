class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> m;
        
        int s=0, res=0;
        
        m[0]=-1;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==0)
                s--;
            else
                s++;
                        
            if(m.find(s)!=m.end()){
                res=max(res,i-m[s]);
            }
            
            if(m.find(s)==m.end()){
                m[s]=i;
            }
        }
        
        return res;
    }
};