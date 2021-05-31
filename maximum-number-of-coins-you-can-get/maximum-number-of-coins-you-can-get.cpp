class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.rbegin(), piles.rend());
        
        int n=piles.size();
        
        int j=1,k=n-1;
        
        int res=0;
        
        while(k>j){
            res+=piles[j];
            j+=2;
            k-=1;
        }
        
        return res;
    }
};