class Solution {
public:
    int countVowelStrings(int n) {
       
        int a=1,e=1,i=1,o=1,u=1;
        
        for(int k=2;k<=n;k++){
                         
            int aa=(a+e+i+o+u), ee=(e+i+o+u), ii=(i+o+u), oo=(o+u), uu=u;
            
            a=aa, e=ee, i=ii, o=oo, u=uu;
        }
        
        return a+e+i+o+u;
    }
};