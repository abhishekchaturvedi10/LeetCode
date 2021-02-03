class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>> graph(n, vector<int>());
        vector<int> degree(n);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]); 
            graph[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(degree[i]==1)
                q.push(i);
        while(n>2){
            n-=q.size();
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                for(int i:graph[x]){
                    degree[i]--;
                    if(degree[i]==1)
                        q.push(i);
                }
            }
        }
        vector<int> res;
        if(q.size()==1){
            int x=q.front();
            res.push_back(x);
        }
        else{
            int x=q.front(), y=q.back();
            res.push_back(x), res.push_back(y);
        }
        return res;
    }
};