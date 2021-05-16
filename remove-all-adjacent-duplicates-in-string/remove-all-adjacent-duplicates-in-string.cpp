class Solution {
public:
    string removeDuplicates(string ss) {
        
        stack<char> s;
        
        for(char x:ss){
            if(s.empty())
                s.push(x);
            else{
                if(s.top()==x)
                    s.pop();
                else
                    s.push(x);
            }
        }
        
        string res;
        
        while(!s.empty())
            res+=s.top(), s.pop();
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};