class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1=0, s2=0, res=0, diff;
        for(int n1:nums1) {
            s1+=n1;
        }
        for(int n2:nums2) {
            s2+=n2;
        }
        diff=abs(s1-s2);
        vector<int> diffs;
        for(int& n1:nums1) {
            if(s1<s2) {
                if(n1<6) {
                    diffs.push_back(6-n1);
                }
            } else {
                if(n1>1) {
                    diffs.push_back(n1-1);
                }
            }
        }
        for(int& n2:nums2) {
            if(s1>s2) {
                if(n2<6) {
                    diffs.push_back(6-n2);
                }
            } else {
                if(n2>1) {
                    diffs.push_back(n2-1);
                }
            }
        }
        sort(diffs.rbegin(),diffs.rend());
        for(int& x:diffs) {
            if(diff<=0) {
                break;
            }
            diff-=x;
            res++;
        }
        return diff<=0?res:-1;
    }
};