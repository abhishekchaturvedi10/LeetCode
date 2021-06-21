class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> m;
        
        int res=1;
        
        for(int i:arr){
            
            if(m.find(i-difference)==m.end()){
                m[i]=1;
            }
            else{
                m[i]=m[i-difference]+1;
                res=max(res, m[i]);
            }
        }
        
        return res;
    }
};