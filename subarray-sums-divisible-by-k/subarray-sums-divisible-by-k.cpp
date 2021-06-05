class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        
        unordered_map<int,int> m;
                
        int n=a.size(), cur=0, res=0;
        
        m[0]=1;
        
        for(int i=0;i<n;i++){
            
            cur=(cur+a[i])%k;
            
            if(cur<0)
                cur+=k;
            
            res+=m[cur];
            
            m[cur]++;
        }
        
        return res;
    }
};