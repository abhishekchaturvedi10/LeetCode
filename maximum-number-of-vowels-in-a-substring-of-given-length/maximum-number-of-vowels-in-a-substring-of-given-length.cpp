class Solution {
public:
    int maxVowels(string s, int k) {
        
        int res=0, i=1, j=0, cnt=0;;
        
        while(j<k){
            
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                cnt++;
            
            j++;
        }
        
        res=cnt;
        
        while(j<s.size()){
            
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u')
                cnt--;
            
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                cnt++;
            
            i++;
            j++;
            
            res=max(res,cnt);
        }
        
        return res;
    }
};