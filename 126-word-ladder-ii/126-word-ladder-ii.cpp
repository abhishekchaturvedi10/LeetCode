class Solution {
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordLis) {
                        
        int lol=INT_MAX;
        
        unordered_set<string> wordList;
        
        for(auto s:wordLis)
            wordList.insert(s);
        
        vector<vector<string>> res;
        
        queue<vector<string>> q;
        
        q.push({beginWord});
                
        while(q.size()>0) {
                        
            int n=q.size();
            
            while(n--) {
                
                auto s=q.front();
                
                q.pop();  
                
                if(s.back()==endWord&&(lol==INT_MAX||s.size()==lol)) {
                    res.push_back(s);
                    lol=s.size();
                    continue;
                }
                
                if(s.size()>=lol)
                    continue;
                
                wordList.erase(s.back());
                
                for(auto &ss:wordList) {
                    
                    int cnt=0;
                    
                    for(int i=0;i<ss.size();i++) {
                        if(ss[i]!=s.back()[i])
                            cnt++;
                        if(cnt>1)
                            break;
                    }
                            
                    if(cnt==1){
                        vector<string> v=s;
                        v.push_back(ss);
                        q.push(v);
                    }
                }
            }
        }
        
        return res;
    }
};