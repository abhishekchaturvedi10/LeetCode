class Solution {
public:
    string removeOuterParentheses(string ss) {
        
        string res="";
        
        string x="";
        
        stack<int> s;
        
        for(char i:ss){
            x+=i;
            if(i=='('){
                s.push(i);
            }
            else{                
                s.pop();
                if(s.empty()){
                    if(x.size()>2){
                        string y="";
                        for(int j=1;j<x.size()-1;j++)
                            y+=x[j];
                        res+=y;
                    }
                    x="";
                }
            }
        }
        
        return res;
    }
};