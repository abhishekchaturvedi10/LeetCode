class Solution {
public:
    
    unordered_map<string, int> m;
    
    bool rec(string &nums, int req) {
        
        if(m.count(nums))
            return m[nums];
        
        if(nums.back()-'0'>=req)
            return m[nums]=1;
        
        for(int i=0;i<nums.size();i++) {
            
            string cur=nums.substr(0,i)+nums.substr(i+1);
            
            if(!rec(cur, req-(nums[i]-'0')))
                return m[nums]=1;
        }
        
        return m[nums]=0;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        if((maxChoosableInteger+1)*(maxChoosableInteger)/2<desiredTotal)
            return 0;
        
        if(desiredTotal==0)
            return 1;
        
        string s;
        
        for(int i=1;i<=maxChoosableInteger;i++)
            s+=(i+'0');
        
        return rec(s, desiredTotal);
    }
};