class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string a,b;
        
        for(char i:s){
            if(i=='#'){
                if(!a.empty()){
                    a.pop_back();
                }
            }
            else{
                a+=i;
            }
        }
        
        for(char i:t){
            if(i=='#'){
                if(!b.empty()){
                    b.pop_back();
                }
            }
            else{
                b+=i;
            }
        }
        
        return a==b;
    }
};