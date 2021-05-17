class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> start;
         
        map<int,int> pos;
        
        int ind=1;
        
        for(auto &i:intervals){
            start.push_back(i[0]);
            if(pos[i[0]]==0){
                pos[i[0]]=ind;
            }
            ind++;
        }
        
        vector<int> res;
        
        sort(start.begin(),start.end());
        
        for(auto &i:intervals){
            
            int index=lower_bound(start.begin(),start.end(),i[1])-start.begin();
            
            if(index==intervals.size()){
                res.push_back(-1);
            }
            else{
                res.push_back(pos[start[index]]-1);
            }
        }
        
        return res;
    }
};