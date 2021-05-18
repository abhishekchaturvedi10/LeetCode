class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int net=0, n=gas.size();
        
        for(int i=0;i<n;i++){
            net+=gas[i]-cost[i];
        }
        
        if(net<0)
            return -1;
        
        int start=0;
        net=0;
        
        for(int i=0;i<n;i++){
            net+=gas[i]-cost[i];
            if(net<0){
                net=0;
                start=i+1;
            }
        }
        
        return start;
    }
};