class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int &ans:answers) {
            mp[ans]++;
        }
        int res=0;
        for(auto p:mp) {
            int x=p.first+1;
            int y=p.second/x;
            int z=p.second%x;
            res+=x*y;
            if(z!=0) {
                res+=x;
            }
        }
        return res;
    }
};