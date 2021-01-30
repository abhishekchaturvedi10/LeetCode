class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        map<int, vector<vector<int>>> m;
        map<vector<int>, int> seen;
        for(int i=0;i<=target;i++){
            for(int j:candidates){
                if(j+i>target)
                    continue;
                if(i>0&&m[i].size()==0)
                    continue;
                if(m[i].size()==0){
                    vector<int> cur{j};
                    m[i+j].push_back(cur);
                }
                else{
                    if(i+j==target){
                        for(auto k:m[i]){
                            vector<int> cur = k;
                            cur.push_back(j);
                            sort(cur.begin(), cur.end());
                            if(!seen[cur]){
                                m[i+j].push_back(cur);
                                seen[cur]++;
                            }
                        }
                        continue;
                    }
                    for(auto k:m[i]){
                        vector<int> cur = k;
                        cur.push_back(j);
                        m[i+j].push_back(cur);
                    }
                }
            }
        }
        return m[target];
    }
};