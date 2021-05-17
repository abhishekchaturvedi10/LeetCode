class Solution {
public:
    int minInsertions(string s) {
        
        int res=0;
        
        stack<char> st;
        
        int i=0;
        
        while(i<s.size()){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    res++;
                }
                else{
                    st.pop();
                }
                if(i<s.size()&&s[i+1]==')'){
                    i++;
                }
                else{
                    res++;
                }
            }
            i++;
        }
        
        return res+st.size()*2;
    }
};