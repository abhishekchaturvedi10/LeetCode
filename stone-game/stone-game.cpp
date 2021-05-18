class Solution {
public:
    
    int dp[500][500];
    
    int game(vector<int> &arr, int s, int e){
        
        if(s>e)
            return 0;
        
        if(dp[s][e]!=-1)
            return dp[e][s];
        
        return dp[s][e]=max({arr[s]+game(arr,s+2,e), arr[s]+game(arr,s+1,e-1), arr[e]+game(arr,s+1,e-1), arr[e]+game(arr,s,e-2)});
    }
    
    bool stoneGame(vector<int>& piles) {
        
        memset(dp, -1, sizeof(dp));
        
        int Alex = game(piles, 0, piles.size()-1);
        
        int total=0;
        
        for(int i:piles)
            total+=i;
        
        int Lee = total-Alex;
        
        return Alex>Lee;
    }
};