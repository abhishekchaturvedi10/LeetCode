class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        if(n<=2)
            return 0;
        
        vector<int> maxFromLeft(n,0), maxFromRight(n,0);
        
        maxFromLeft[0]=height[0];
        
        for(int i=1;i<n;i++)
            maxFromLeft[i]=max(height[i],maxFromLeft[i-1]);
        
        maxFromRight[n-1]=height[n-1];
        
        for(int i=n-2;i>=0;i--)
            maxFromRight[i]=max(height[i],maxFromRight[i+1]);
        
        int res=0;
        
        for(int i=1;i<n-1;i++)
            res+=max(0, min(maxFromLeft[i-1],maxFromRight[i+1])-height[i]);
        
        return res;
    }
};