class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        
        if(a[1]==b[1])
            return b[0]>a[0];
        
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp);
        
        int res=0, prev=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prev){
                prev=intervals[i][1];
            }
            else{
                res++;
            }
        }
        
        return res;
    }
};