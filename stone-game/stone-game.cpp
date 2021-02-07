class Solution {
public:
    int dp[500][500];
    
    int game(vector<int>& a, int lo, int hi){
        if(lo > hi) return 0;
        if(dp[lo][hi] != -1) 
            return dp[lo][hi];
        return dp[lo][hi] = max(a[lo] + min(game(a, lo + 2, hi), game(a, lo + 1, hi - 1)), a[hi] + min(game(a, lo + 1, hi - 1), game(a, lo, hi - 2)));
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return (game(piles, 0, piles.size() - 1) > 0);
    }
};