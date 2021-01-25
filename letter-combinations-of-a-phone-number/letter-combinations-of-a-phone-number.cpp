class Solution {
public:
    vector<string> ans;
    void helper(string digits, string cur, int i){
        if(i==digits.size()){
            ans.push_back(cur);
            return;
        }
        int x=digits[i]-'0';
        x-=2;
        if(x<5){
            for(int j=x*3;j<x*3+3;j++)
                helper(digits, cur+(char)(97+j), i+1);
        }
        else if(x==5){
            for(int j=x*3;j<=x*3+3;j++)
                helper(digits, cur+(char)(97+j), i+1);
        }
        else if(x==6){
            for(int j=x*3+1;j<=x*3+3;j++)
                helper(digits, cur+(char)(97+j), i+1);
        }
        else{
            for(int j=x*3+1;j<=x*3+4;j++)
                helper(digits, cur+(char)(97+j), i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        helper(digits, "", 0);
        return ans;
    }
};
