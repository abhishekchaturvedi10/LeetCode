class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(), res=0;
        unordered_map<int,int> seen, vis;

        for(int i:nums) {
            seen[i]=1;
        }

        for(auto i:seen) {
            if(vis[i.first]) {
                continue;
            }
            int x=i.first, len=1;
            vis[i.first]=1;
            while(seen.find(--x)!=seen.end()) {
                len++;
                vis[x]=1;
            }
            x=i.first;
            while(seen.find(++x)!=seen.end()) {
                len++;
                vis[x]=1;
            }
            res=max(res,len);
        }

        return res;
    }
};