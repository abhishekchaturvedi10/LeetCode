class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans=0; 
        map<int,int> m1,m2;
        for(int a:A)
            for(int b:B)
                m1[a+b]++;
        for(int c:C)
            for(int d:D)
                m2[-(c+d)]++;
        for(pair<int,int> i:m1)
            if(m2[i.first]>0)
                ans+=(m2[i.first]*m1[i.first]);
        return ans;
    }
};
