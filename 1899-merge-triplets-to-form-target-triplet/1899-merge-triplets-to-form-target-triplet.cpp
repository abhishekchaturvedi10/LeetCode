class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int ind=-1, mn=INT_MAX;
        
        for(int i=0;i<triplets.size();i++)
            if(triplets[i][0]==target[0]&&triplets[i][1]<=target[1]&&triplets[i][2]<=target[2])
                ind=i;
        
        // cout<<"ind = "<<ind<<endl;
        
        if(ind==-1)
            return 0;
        
        int ind1=-1, mn1=INT_MAX;
        
        for(int i=0;i<triplets.size();i++)
            if(triplets[i][1]==target[1]&&triplets[i][0]<=target[0]&&triplets[i][2]<=target[2])
                ind1=i;
        
        // cout<<"ind1 = "<<ind1<<endl;
        
        if(ind1==-1)
            return 0;
        
        int ind2=-1;
        
        for(int i=0;i<triplets.size();i++)
            if(triplets[i][2]==target[2]&&triplets[i][0]<=target[0]&&triplets[i][1]<=target[1])
                ind2=i;
        
        // cout<<"ind2 = "<<ind2<<endl;
        
        if(ind2==-1)
            return 0;
        
        return 1;
    }
};