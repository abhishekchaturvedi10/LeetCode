class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        unordered_map<char,int> m,n;
        
        for(char& s:word1)
            m[s]++;
        
        for(char& s:word2)
            n[s]++;
        
        multiset<int> w1,w2;
        
        for(auto& i:m)
            w1.insert(i.second);
        
        for(auto& i:n)
            if(m[i.first]>0)
                w2.insert(i.second);
        
        return w1==w2;
    }
};