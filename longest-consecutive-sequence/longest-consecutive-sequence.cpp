class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> m;
        
        for(int i:nums)
            m[i]=1;
        
        int res=0;
        
        for(int i:nums){
            
            if(m[i]==0)
                continue;
            
            int cnt=1;
            
            int x=i;
            
            while(m[x-1]!=0){
                x--;
                cnt++;
                m[x]=0;
            }
            
            x=i;
            
            while(m[x+1]!=0){
                x++;
                cnt++;
                m[x]=0;
            }
            
            res=max(res,cnt);
        }
        
        return res;
    }
};