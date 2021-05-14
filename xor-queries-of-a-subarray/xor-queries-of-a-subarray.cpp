class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        
        vector<int> prexor;
        
        prexor.push_back(a[0]);
        
        for(int i=1;i<a.size();i++)
            prexor.push_back(prexor[i-1]^a[i]);
        
        for(int i:prexor)
            cout<<i<<" ";
        
        vector<int> res;
        
        for(auto i:q)
            res.push_back(prexor[i[1]]^(i[0]==0?0:prexor[i[0]-1]));
        
        return res;
    }
};