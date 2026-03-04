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
        priority_queue<int> h1, h2;
        for(int& n1:nums1) {
            if(s1<s2) {
                if(n1<6) {
                    h1.push(6-n1);
                }
            } else {
                if(n1>1) {
                    h1.push(n1-1);
                }
            }
        }
        for(int& n2:nums2) {
            if(s1>s2) {
                if(n2<6) {
                    h2.push(6-n2);
                }
            } else {
                if(n2>1) {
                    h2.push(n2-1);
                }
            }
        }
        while(!h1.empty()||!h2.empty()) {
            if(diff<=0) {
                return res;
            }
            res++;
            if(!h1.empty()&&!h2.empty()) {
                if(h1.top()>h2.top()) {
                    diff-=h1.top();
                    h1.pop();
                } else {
                    diff-=h2.top();
                    h2.pop();
                }
            } else if(!h1.empty()) {
                diff-=h1.top();
                h1.pop();
            } else {
                cout<<h2.top()<<endl;
                diff-=h2.top();
                h2.pop();
            }
        }
        return diff<=0?res:-1;
    }
};