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
            res+=x*(p.second/x);
            if(p.second%x!=0) {
                res+=x;
            }
        }
        return res;
    }
};