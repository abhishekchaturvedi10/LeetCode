class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
                
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i]!=st.top().first){
                st.push({s[i],1});
            }
            else{
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
        }
        
        string res;
        
        while(!st.empty()){
            int x=st.top().second;
            while(x--){
                res+=st.top().first;
            }
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};