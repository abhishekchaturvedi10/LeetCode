class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> ope, st;
        
        for(char c:expression){
            
            if(c==',')
                continue; 
            
            else if(c=='f'||c=='t'||c=='(')
                st.push(c);
            
            else if(c==')'){
                
                vector<int> x;
                
                while(st.top()!='('){
                    
                    if(st.top()=='t')
                        x.push_back(1);
                    else
                        x.push_back(0);
                    
                    st.pop();
                }
                
                st.pop();
                                
                if(ope.top()=='!'){
                    
                    st.push(x[0]==1?'f':'t');
                }
                else if(ope.top()=='|'){
                    
                    int res=x[0];
                    
                    for(int i=1;i<x.size();i++)
                        res|=x[i];
                    
                    st.push(res==1?'t':'f');
                }
                else{
                    
                    int res=x[0];
                    
                    for(int i=1;i<x.size();i++)
                        res&=x[i];
                    
                    st.push(res==1?'t':'f');
                }
                
                ope.pop();
            }
            else
                ope.push(c);
        }
        
        return st.top()=='t'?1:0;
    }
};