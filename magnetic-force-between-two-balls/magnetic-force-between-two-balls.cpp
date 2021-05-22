class Solution {
public:
    int maxDistance(vector<int>& position, int balls) {
        
        //Sorting the positions so that we can apply binary search
        
        sort(position.begin(),position.end());
        
        int n=position.size();
        
        int l=1, r=position[n-1]-position[0];
        
        int res=1;
        
        while(r>=l){
            
            int m=l+(r-l)/2;
            
            int count=0;
            
            //Placing the first ball always on 0th index 
            
            count++;
            
            int i=1;
            
            while(count<balls&&i<n){
                
                
                // The minimum x coordinate of position of the current ball that needs to be so that the distance is m
                
                int x=position[i-1]+m;
                
                
                // Checking in the positon array for the x coordinate that has value >=x
                
                int j=lower_bound(position.begin()+i,position.end(),x)-position.begin();
                

                // If position found in the array update the count of balls placed 
                
                if(j<n)
                    count++;
                else
                    break;
                
                // Now we can only place balls from j+1 to n-1
                
                i=j+1;
            }
            
            // Checking if we can place all the balls and if we can we upadte the result and increase the minimum gap between two balls else we decrease it
            
            if(count==balls)
                res=max(res,m), l=m+1;
            else
                r=m-1;
        }
        
        return res;
    }
};