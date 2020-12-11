class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k=-1; bool flag=true;
        for(int i=0;i<s.size();i++){
            flag=true;
            for(int j=k+1;j<t.size();j++){
                if(s[i]==t[j]){
                    k=j; flag=false; break;
                }
            }
            if(flag) return false;
        }
        return true;
    }
};
