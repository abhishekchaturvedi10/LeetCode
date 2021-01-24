class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        vector<int> a(amount+1);
        for(int i=amount;i>=1;i--){
            for(int j:coins){
                if(i==amount){
                    if(i-j>=0){
                        a[i-j]=1;
                    }
                }
                else{
                    if(a[i]>0&&i-j>=0){
                        if(a[i-j]>0)
                            a[i-j]=min(a[i-j],a[i]+1);
                        else
                            a[i-j]=a[i]+1;
                    }
                }
            }
        }
        for(int i=amount;i>=1;i--)
            cout<<a[i]<<" ";
        if(a[0]==0)
            return -1;
        return a[0];
    }
};
