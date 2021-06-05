class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        if(arr.size()<3)
            return 0;
        
        int i=0, res=0;
        
        while(i<arr.size()){
            
            int j=i;
            
            int f=0,f1=0;
            
            while(j<arr.size()-1&&arr[j+1]>arr[j]){
                f=1;
                j++;
            }
            
            int k=j;
            
            while(k<arr.size()-1&&arr[k]>arr[k+1]){
                k++;
                f1=1;
            }
            
            // cout<<f<<" "<<f1<<'\n';
            
            if(k-i>=2&&f==1&&f1==1){
                if(k<arr.size())
                    res=max(res, k-i+1);
                else
                    res=max(res, k-i);
            }
            
            // cout<<i<<" "<<j<<" "<<k<<'\n';
            
            if(k<arr.size()&&arr[j]==arr[k])
                i=k+1;
            else
                i=k;
        }
        
        return res;
    }
};