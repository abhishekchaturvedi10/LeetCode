class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        int sum=boxes[0]-'0';
        for(int i=1;i<n;i++){
            res[i]=res[i-1]+sum;
            sum+=boxes[i]-'0';
        }
        sum=boxes[n-1]-'0';
        int x=0;
        for(int i=n-2;i>=0;i--){
            x+=sum;
            res[i]+=x;
            sum+=boxes[i]-'0';
        }
        return res;
    }
};