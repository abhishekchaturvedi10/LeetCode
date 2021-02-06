class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int x=0;
        for(int i=0;i<s1.size();i++){
            if(s2[i]>s1[i]){
                x=1;
                break;
            }
        }
        if(x==0)
            return true;
        x=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]>s2[i]){
                x=1;
                break;
            }
        }
        if(x)
            return false;
        return true;
    }
};