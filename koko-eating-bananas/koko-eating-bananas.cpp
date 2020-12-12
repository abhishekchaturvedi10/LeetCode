class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        if(piles.size()==1){
            if(piles[0]>H)
                return 2;
            else 
                return 1;
        }
        int l=1,maxi=0,mid,ans;
        for(int i=0;i<piles.size();i++)
            maxi=max(maxi,piles[i]);
        ans=maxi;
        while(maxi>=l){
            int h=0;
            mid=(maxi+l)/2;
            for(int i=0;i<piles.size();i++){
                h+=piles[i]/mid;
                if(piles[i]%mid)
                    h+=1;
            }                   
            cout<<maxi<<" "<<l<<" "<<h<<endl;
            if(h<=H){
                ans=min(ans,mid);
                maxi=mid-1;
            }
            else 
                l=mid+1;
        }
        return ans;
    }
};
