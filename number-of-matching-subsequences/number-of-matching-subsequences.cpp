class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<char, vector<int>> m;
        
        for(int i=0;i<s.size();i++)
            m[s[i]].push_back(i);
        
        int res=0;
        
        for(auto word:words){
            
            int prev=-1;
            
            bool f=1;
            
            for(char i:word){
                
                int ind=upper_bound(m[i].begin(), m[i].end(), prev) - m[i].begin();
                
                if(ind==m[i].size()){
                    f=0;
                    break;
                }
                
                prev=m[i][ind];
            }
            
            if(f)
                res++;
        }
        
        return res;
    }
};