class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int memo[1005][1005];
        for (int i=0; i < A.size(); i++) 
            for (int j=0; j < B.size(); j++)
                memo[i][j]=0;
        for (int i = A.size() - 1; i >= 0; --i) {
            for (int j = B.size() - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    ans = max(ans, memo[i][j]);
                }
            }
        }
        return ans;
    }
};
