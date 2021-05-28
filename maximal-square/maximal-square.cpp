class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        
        int l=0, r=min(m,n), res=0;
        
        while(r>=l){
            
            int mid=l+(r-l)/2;
                        
            bool found=0;
            
            for(int i=0;i<m;i++){
                
                if(i+mid>m)
                    break;
                                
                for(int j=0;j<n;j++){
                    
                    if(j+mid>n)
                        break;
                    
                    int isPresent=1;
                    
                    for(int k=i;k<i+mid;k++){
                        for(int l=j;l<j+mid;l++){
                            if(matrix[k][l]=='0'){
                                isPresent=0;
                            }
                        }
                    }
                    
                    if(isPresent){
                        found=1;
                        break;
                    }
                }
                
                if(found)
                    break;
            }
            
            if(found){
                l=mid+1;
                res=max(res,mid*mid);
            }
            else
                r=mid-1;
        }
        
        return res;
    }
};