class Solution {
public:

    vector<vector<int>> res;

    void helper(vector<int>& candidates, int i, int target, vector<int> curComb) {
        
        if(target<0) {
            return;
        }

        if(target==0) {
            res.push_back(curComb);
        }

        if(i>=candidates.size()) {
            return;
        }

        if(candidates[i]>target) {
            return;
        }

        int j=i+1;
        while(j<candidates.size() && candidates[i]==candidates[j]) {
            j++;
        }
        
        helper(candidates,j,target,curComb);
        
        curComb.push_back(candidates[i]);
        helper(candidates,i+1,target-candidates[i],curComb);
        curComb.pop_back();        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,{});

        return res;
    }
};