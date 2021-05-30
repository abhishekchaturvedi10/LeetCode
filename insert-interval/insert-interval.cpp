class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& i) {
        
        if(intervals.empty())
            return {i};
        
        if(i[1]<intervals[0][0]){
            
            intervals.insert(intervals.begin(), i);
            
            return intervals;
        }
        
        int n=intervals.size();
        
        if(i[0]>intervals[n-1][1]){
            
            intervals.push_back(i);
            
            return intervals;
        }
        
        if(i[1]<=intervals[0][1]){
            
            intervals[0][0]=min(i[0], intervals[0][0]);
            
            intervals[0][1]=max(i[1], intervals[0][1]);
            
            return intervals;
        }
        
        if(i[0]>=intervals[n-1][0]){
            
            intervals[n-1][0]=min(i[0], intervals[n-1][0]);
            
            intervals[n-1][1]=max(i[1], intervals[n-1][1]);
            
            return intervals;
        }
        
        
        
        int ii=0;
        
        while(ii<n&&i[0]>intervals[ii][1]){
            ii++;
        }
        
        int j=ii;
          
        while(j<n&&i[1]>=intervals[j][0]){
            j++;
        }
        
        if(j<n&&intervals[j][0]>i[1])
            j--;
         
        if(j==n)
            j--;
        
        vector<vector<int>> res;
        
        for(int k=0;k<ii;k++){
            res.push_back(intervals[k]);
        }
        
        res.push_back({min(intervals[ii][0],i[0]), max(intervals[j][1],i[1])});
        
        for(int k=j+1;k<n;k++){
            res.push_back(intervals[k]);   
        }
        
        return res;
    }
};