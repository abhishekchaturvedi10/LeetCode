class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<vector<int>> projects;
        for(int i=0;i<n;i++) {
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        priority_queue<int> pq;
        int j=0;
        for(int i=0;i<k;i++) {
            while(j<n&&projects[j][0]<=w) {
                pq.push(projects[j][1]);
                j++;
            }
            if(pq.empty()) {
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};