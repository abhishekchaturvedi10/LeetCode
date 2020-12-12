class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans=0; 
        map<int,int> m1;
        for(int a:A)
            for(int b:B)
                m1[a+b]++;
        for(int c:C)
            for(int d:D)
                ans+=m1[-(c+d)];
        return ans;
    }
};