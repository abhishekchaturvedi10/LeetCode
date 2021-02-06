class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(i);
                i++;
            }
            else if(s[i]==')'){
                if(st.empty()){
                    s.erase(i, 1);
                }
                else{
                    st.pop();
                    i++;
                }
            }
            else
                i++;
        }
        while(!st.empty()){
            i=st.top();
            s.erase(i, 1);
            st.pop();
        }
        return s;
    }
};