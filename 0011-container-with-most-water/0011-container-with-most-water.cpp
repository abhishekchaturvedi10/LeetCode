class Solution {
public:
    int fun(vector<int>& height) {
        int l=0,r=height.size()-1,res=0;
        while(l<r) {
            res=max(res,(r-l)*min(height[l],height[r]));
            if(height[r]>height[l]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
    int maxArea(vector<int>& height) {
        return fun(height);
    }
};