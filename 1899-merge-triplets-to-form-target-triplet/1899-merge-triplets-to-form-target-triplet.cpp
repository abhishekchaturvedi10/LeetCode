class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<int> lol(3);
        
        for(auto& v:triplets)
            if(v[0]<=target[0]&&v[1]<=target[1]&&v[2]<=target[2])
                lol[0]=max(lol[0],v[0]), lol[1]=max(lol[1],v[1]), lol[2]=max(lol[2],v[2]);
    
        return lol==target;
    }
};