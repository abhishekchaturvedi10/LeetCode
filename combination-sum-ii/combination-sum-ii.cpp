class Solution {
public:
    
    vector<vector<int>> res;
        
    void rec(int tar, int i, vector<int>& coins, vector<int> v){
        
        if(tar==0){
            
            res.push_back(v);            
            return;
        }
        
        if(i==coins.size()||coins[i]>tar)
            return;
        
        v.push_back(coins[i]);
                
        rec(tar-coins[i], i+1, coins, v);
                
        v.pop_back();
        
        int j=i+1;
        
        while(j<coins.size()&&coins[j]==coins[i])
            j++;
        
        if(j<coins.size())
            rec(tar,j,coins,v);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        rec(target, 0, candidates, {});
        
        return res;
    }
};