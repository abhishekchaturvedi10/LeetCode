class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(), res=0;
        unordered_set<int> seen, vis;

        for(int i:nums) {
            seen.insert(i);
        }

        for(int i:seen) {
            if(vis.count(i)) {
                continue;
            }
            int x=i, len=1;
            vis.insert(i);
            while(seen.count(--x)) {
                len++;
                vis.insert(x);
            }
            x=i;
            while(seen.count(++x)) {
                len++;
                vis.insert(x);
            }
            res=max(res,len);
        }

        return res;
    }
};