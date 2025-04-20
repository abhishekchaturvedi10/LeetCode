class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(int &ans:answers) {
            mp[ans]++;
        }
        int res=0;
        for(auto p:mp) {
            if(p.first==0) {
                res+=mp[0];
            } else {
                int x=p.first+1;
                int y=p.second/x;
                int z=p.second%x;
                res+=x*y;
                if(z!=0) {
                    res+=x;
                }
            }
        }
        return res;
    }
};