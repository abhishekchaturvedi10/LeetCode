class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int tot=0,minn=0;
        for(int i=0;i<weights.size();i++)
            tot+=weights[i], minn=max(minn,weights[i]);
        int ans=tot;
        while(tot>=minn){
            int mid=(tot+minn)/2;
            //cout<<minn<<" "<<tot<<" "<<mid<<endl;
            int d=1, sum=0;
            for(int i=0;i<weights.size();i++){
                sum+=weights[i];
                if(sum>mid){
                    sum-=weights[i];
                    sum=weights[i];
                    d++;
                }
                else if(sum==mid){
                    d++;
                    sum=0;
                }
            }
            if(sum>mid) d++;
            cout<<mid<<" "<<d<<endl;
            if(d>D){
                minn=mid+1;
            }
            else{
                ans=min(ans,mid);
                tot=mid-1;
            }
        }
        return ans;
    }
};
