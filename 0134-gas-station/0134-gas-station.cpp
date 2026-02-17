class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0, totalGas = 0;

        for(int i=0;i<gas.size();i++) {
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost>totalGas) {
            return -1;
        }

        int res=0;
        totalCost = 0, totalGas = 0;

        for(int i=0;i<gas.size();i++) {
            totalGas+=gas[i];
            totalCost+=cost[i];
            if(totalGas<totalCost) {
                totalCost = 0, totalGas = 0;
                res=i+1;
            }
        }

        return res;
    }
};