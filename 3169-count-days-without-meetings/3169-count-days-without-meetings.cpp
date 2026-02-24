class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        int res=0, n=meetings.size();

        int start=meetings[0][0], end=meetings[0][1];
        res+=(start-1);

        for(int i=1;i<n;i++) {
            if(meetings[i][0]>end) {
                res+=max(0,meetings[i][0]-end-1);
            }
            start=min(meetings[i][0],start), 
            end=max(meetings[i][1],end);
        }

        return res+max(0,days-end);
    }
};