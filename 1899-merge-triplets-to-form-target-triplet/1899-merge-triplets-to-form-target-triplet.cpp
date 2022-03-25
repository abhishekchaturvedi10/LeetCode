class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int ind=-1;
        
        for(int i=0;i<triplets.size();i++)
            if(triplets[i][0]==target[0]&&triplets[i][1]<=target[1]&&triplets[i][2]<=target[2])
                ind=i;
                
        if(ind==-1)
            return 0;
        
        int ind1=-1;
        
        for(int i=0;i<triplets.size();i++)
            if(triplets[i][1]==target[1]&&triplets[i][0]<=target[0]&&triplets[i][2]<=target[2])
                ind1=i;
                
        if(ind1==-1)
            return 0;
        
        int ind2=-1;
        
        for(int i=0;i<triplets.size();i++)
            if(triplets[i][2]==target[2]&&triplets[i][0]<=target[0]&&triplets[i][1]<=target[1])
                ind2=i;
                
        if(ind2==-1)
            return 0;
        
        return 1;
    }
};