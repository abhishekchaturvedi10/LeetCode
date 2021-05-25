class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(!left)
            return 0;
        
        if(left==right)
            return left;
                        
        if((int)log2(left)!=(int)log2(right))
            return 0;
        
        for(long long i=left+1;i<=right;i++){
            
            left&=i;
            
            if(!left)
                return 0;
        }
        
        return left;
    }
};