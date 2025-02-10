class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        while(n>0) {
            string x="";
            bool found=false;
            for(int i=0;i<n;i++) {
                if(!found && isdigit(s[i])) {
                    found=true;
                    if(x.size()>0) {
                        x.pop_back();
                    }
                } else {
                    x+=s[i];
                }
            }
            cout<<endl;
            if(!found) {
                return x;
            } else {
                n=x.size();
                s=x;
            }
        }
        return "";
    }
};