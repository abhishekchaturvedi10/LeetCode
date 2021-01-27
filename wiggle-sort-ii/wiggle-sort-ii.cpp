class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a, b;
        int n=nums.size()/2;
        if(nums.size()%2==0)
            n--;
        for(int i=0;i<=n;i++){
            a.push_back(nums[i]);
            //cout<<nums[i]<<" ";
        }
        for(int i=n+1;i<nums.size();i++)
            b.push_back(nums[i]);
        int i=a.size()-1, j=0;
        while(i>-1){
            nums[j]=a[i--];
            j+=2;
        }
        i=b.size()-1; j=1;
        while(i>-1){
            nums[j]=b[i--];
            j+=2;
        }
    }
};