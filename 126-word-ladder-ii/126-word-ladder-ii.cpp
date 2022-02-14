class Solution {
public:

    int fun(string beginWord, string endWord, vector<string>& wordList) {
                
        int res=0;
        
        queue<string> q;
        
        q.push(beginWord);
        
        unordered_set<string> seen;
        
        while(q.size()>0) {
            
            res++;
            
            int n=q.size();
                        
            while(n--) {
                
                auto s=q.front();
                
                q.pop();    
                                
                if(s==endWord)
                    return res;
                
                if(seen.count(s))
                    continue;
                
                seen.insert(s);
                
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
                        if(cnt==1){
                            q.push(ss);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordLis) {
                        
        int lol=fun(beginWord,endWord,wordLis);
                        
        if(lol==0) {
            return {};
        }
        
        unordered_set<string> wordList;
        
        for(auto s:wordLis)
            wordList.insert(s);
        
        vector<vector<string>> res;
        
        queue<vector<string>> q;
        
        q.push({beginWord});
        
        unordered_set<string> seen;
        
        while(q.size()>0) {
                        
            int n=q.size();
            
            while(n--) {
                
                auto s=q.front();
                
                q.pop();  
                
                if(s.back()==endWord&&s.size()==lol) {
                    res.push_back(s);
                    continue;
                }
                
                if(s.size()>=lol)
                    continue;
                
                wordList.erase(s.back());
                
                for(auto &ss:wordList) {
                    if(ss.size()==s.back().size()) {
                        int cnt=0;
                        seen.insert(ss);
                        for(int i=0;i<ss.size();i++) {
                            if(ss[i]!=s.back()[i]){
                                cnt++;
                                if(cnt>1)
                                    break;
                            }
                        }
                        if(cnt==1){
                            vector<string> v=s;
                            v.push_back(ss);
                            q.push(v);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};