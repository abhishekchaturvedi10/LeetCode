class Solution {
public:
    
    // Mini, Maxi represnt the interval of minimum and maximum open brackets
    
    bool checkValidString(string s) {
        
        int mini=0, maxi=0;
                
        for(char c:s){
                        
            if(c=='(')
                 mini++, maxi++;
            else if(c==')')
                mini=max(mini-1,0),maxi--;
            else 
                mini=max(mini-1,0), maxi++;
            
            if(maxi<0)
                return 0;
        }
        
        return mini==0;
    }
};