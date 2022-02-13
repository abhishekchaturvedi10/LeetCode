class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int res=0;
        
        queue<string> q;
        
        q.push(beginWord);
        
        map<string,int> seen;
        
        while(q.size()>0) {
            
            res++;
            
            int n=q.size();
            
            while(n--) {
                
                string s=q.front();
                
                q.pop();    
                
                if(s==endWord)
                    return res;
                
                if(seen[s])
                    continue;
                
                seen[s]++;
                
                for(auto &ss:wordList) {
                    if(ss.size()==s.size()) {
                        int cnt=0;
                        for(int i=0;i<ss.size();i++) {
                            if(ss[i]!=s[i]){
                                cnt++;
                                if(cnt>1)
                                    break;
                            }
                        }
                        if(cnt==1)
                            q.push(ss);
                    }
                }
            }
        }
        
        return 0;
    }
};