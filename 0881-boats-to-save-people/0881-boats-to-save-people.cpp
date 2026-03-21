class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());

        int n=people.size(), l=0, r=n-1, res=0;

        while(l<=r) {
            if(l==r) {
                r--;
                res++;
            } else {
                if(people[l]+people[r]<=limit) {
                    l++;
                    r--;
                } else {
                    r--;
                }
                res++;
            }
        }

        return res;
    }
};