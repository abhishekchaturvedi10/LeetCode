class Solution {
public:
    
    int dp[366];
    
    unordered_map<int,int> travelDays;
    
    int rec(vector<int> &days, vector<int> &costs, int curday, int n){
                        
        if(curday>days[n-1])
            return 0;
        
        if(dp[curday]!=-1)
            return dp[curday];
        
        int x=min({costs[0]+rec(days,costs,curday+1,n),costs[1]+rec(days,costs,curday+7,n),costs[2]+rec(days,costs,curday+30,n)}); 
        
        if(travelDays[curday]==0)
            x=min(x,rec(days,costs,curday+1,n));            
        
        return dp[curday]=x;
    }    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(dp,-1,sizeof(dp));
        
        for(int i:days)
            travelDays[i]++;
               
        return rec(days,costs,days[0],days.size()); 
    }
};