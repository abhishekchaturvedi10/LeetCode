class Solution {
public:
    int numSplits(string s) {
        vector<int> aage, peeche;
        aage.push_back(1);
        peeche.push_back(1);
        map<char, int> m;
        m[s[0]]=1;
        for(int i=1;i<s.size();i++){
            if(m[s[i]])
                aage.push_back(aage[i-1]);
            else{
                m[s[i]]++;
                aage.push_back(aage[i-1]+1);
            }
        }
        map<char, int> mm;
        mm[s[s.size()-1]]=1;
        for(int i=s.size()-2;i>=0;i--){
            if(mm[s[i]])
                peeche.push_back(peeche[s.size()-2-i]);
            else{
                mm[s[i]]++;
                peeche.push_back(peeche[s.size()-2-i]+1);
            }
        }
        int res=0;
        for(int i=0;i<s.size()-1;i++)
            if(aage[i]==peeche[s.size()-2-i])
                res++;
        return res;
    }
};