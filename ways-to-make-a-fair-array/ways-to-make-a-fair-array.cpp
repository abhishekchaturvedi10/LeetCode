class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        int oddsum[n], evensum[n];
        for(int i=0;i<n;i++){
            if(i%2){
                oddsum[i]=oddsum[i-1]+nums[i];
                evensum[i]=evensum[i-1];
            }
            else{
                if(i==0)
                    evensum[i]=nums[i], oddsum[i]=0;
                else{
                    evensum[i]=evensum[i-1]+nums[i];
                    oddsum[i]=oddsum[i-1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=evensum[n-1]-evensum[i];
            if(i>0)
                x+=oddsum[i-1];
            int y=oddsum[n-1]-oddsum[i];
            if(i>0)
                y+=evensum[i-1];
            if(x==y)
                ans++;
        }
        return ans;
    }
};