class Solution
{
public:
    int trap(vector<int> &height) {
        int res=0, l=0, r=height.size()-1, leftMax=0, rightMax=0;
        while(r>=l) {
            if(height[l]<=height[r]) {
                if(height[l]>=leftMax) {
                    leftMax=height[l];
                } else {
                    res+=(leftMax-height[l]);
                }
                l++;
            } else {
                if(height[r]>=rightMax) {
                    rightMax=height[r];
                } else {
                    res+=(rightMax-height[r]);
                }
                r--;
            }
        }
        return res;
    }
};