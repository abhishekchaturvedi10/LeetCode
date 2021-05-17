class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26);
        
        for(char ch:s) 
            cnt[ch-'a']++;
        
        vector<int> inres(26);
        
        string res;
        
        for(char i:s){
            
            cnt[i-'a']--;
            
            if(res.empty()){
                res+=i;
                inres[i-'a']=1;
                continue;
            }
            
            if(inres[i-'a'])
                continue;
            
            // We need to check count so that we add the removed character in future 
            
            while(!res.empty()&&res.back()>i&&cnt[res.back()-'a']>0){
                inres[res.back()-'a']=0;
                res.pop_back();
            }
            
            res+=i;
            inres[i-'a']=1;
        }
        
        return res;
    }
};