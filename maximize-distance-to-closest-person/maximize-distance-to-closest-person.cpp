class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int l[seats.size()], r[seats.size()];
        
        vector<int> A=seats;
        
        if(seats[0]==1){
            l[0]=0;
        }
        else{
            l[0]=-1;
        }
        
        for(int i=1;i<seats.size();i++){
            if(seats[i]==1)
                l[i]=i;
            else
                l[i]=l[i-1];
        }
        
        if(seats[A.size()-1]==1){
            r[A.size()-1]=A.size()-1;
        }
        else{
            r[A.size()-1]=A.size();
        }
        
        for(int i=seats.size()-2;i>=0;i--){
            if(seats[i]==1)
                r[i]=i;
            else
                r[i]=r[i+1];
        }
        
        int res=0;
        
        for(int i=1;i<A.size()-1;i++){
            if(seats[i]==0){                
                res=max(res, min(i-l[i-1],r[i+1]-i));
            }
        }
        
        if(seats[0]==0)
            res=max(res,r[1]);
        
        if(seats[A.size()-1]==0)
            res=max(res,(int)A.size()-1-l[A.size()-2]);
        
        return res;
    }
};