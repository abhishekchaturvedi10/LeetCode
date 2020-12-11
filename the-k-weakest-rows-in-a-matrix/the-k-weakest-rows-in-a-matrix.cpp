class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> soldiersCount;
        for(int i=0;i<mat.size();i++){
            int l=0,r=mat[i].size()-1;
            int cur=0;
            while(r>=l){
                int mid=(l+r)/2;
                if(mat[i][mid]==1){
                    cur+=mid-l+1;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            soldiersCount.push_back({cur,i});
        }
        sort(soldiersCount.begin(),soldiersCount.end());
        vector<int> ans; int i=0;
        while(k-->0){
            ans.push_back(soldiersCount[i].second);
            i++;
        }
        return ans;
    }
};
