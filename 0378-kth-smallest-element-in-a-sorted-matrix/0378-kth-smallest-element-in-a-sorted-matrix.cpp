class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        int m=matrix.size(), n=matrix[0].size(), ans;

        for(int i=0;i<min(m,k);i++) {
            pq.push({matrix[i][0],i,0});
        }

        while(k--) {
            vector<int> x = pq.top();
            pq.pop();
            ans=x[0];
            int r=x[1], c=x[2];
            if(c+1<n) {
                pq.push({matrix[r][c+1],r,c+1});
            }
        }

        return ans;
    }
};