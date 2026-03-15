class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        
        int n=prices.size();
        long long maxProfit;
        vector<long long> presum(n), profits(n);
        presum[0]=prices[0];
        profits[0]=prices[0]*strategy[0];

        for(int i=1;i<n;i++) {
            presum[i]=presum[i-1]+prices[i];
            profits[i]=profits[i-1]+prices[i]*strategy[i];
        }

        maxProfit=profits[n-1];

        for(int i=0;i+k-1<n;i++) {
            long long curProfit=0;
            if(i>0) {
                curProfit+=profits[i-1];
            }
            curProfit+=(profits[n-1]-profits[i+k-1]);
            curProfit+=(presum[i+k-1]-presum[i+k/2-1]);
            maxProfit=max(maxProfit,curProfit);
        }

        return maxProfit;
    }
};