class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2; // longest substring with k distinct characters
        int l=0,r=0,res=0;
        unordered_map<int,int> m;
        while(r<fruits.size()) {
            if(m.find(fruits[r])==m.end()) {
                if(m.size()<k) {
                    res=max(res,r-l+1);
                    m[fruits[r]]++;
                    r++;
                } else {
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0) {
                        m.erase(fruits[l]);
                    }
                    l++;
                }
            } else {
                res=max(res,r-l+1);
                m[fruits[r]]++;
                r++;
            }
        }
        return res;
    }
};