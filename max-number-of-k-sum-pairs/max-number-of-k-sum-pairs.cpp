class Solution {
public:
    int maxOperations(vector<int>& A, int k) {
        
        sort(A.begin(),A.end());
        
        int i=0, j=A.size()-1;
        
        int res=0;
        
        while(j>i){
            if(A[i]+A[j]==k){
                res++;
                i++;
                j--;
            }
            else if(A[i]+A[j]>k)
                j--;
            else
                i++;
        }
        
        return res;
    }
};