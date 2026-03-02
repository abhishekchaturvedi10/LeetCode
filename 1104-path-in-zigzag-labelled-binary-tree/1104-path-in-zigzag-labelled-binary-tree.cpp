class Solution {
public:

    

    vector<int> pathInZigZagTree(int& label) {
        
        unordered_map<int,int> par;
        par[1]=-1;
        queue<int> q;
        q.push(1);
        int level=1;
        bool labelFound=false;

        while(!labelFound) {
            level++;
            int startVal=pow(2,level-1), endVal=pow(2,level)-1;
            int n=q.size();
            while(n--) {
                int x=q.front();
                q.pop();
                if(x==label) {
                    labelFound=true;
                    break;
                }
                if(level&1) {
                    q.push(startVal);
                    par[startVal]=x;
                    startVal++;
                    q.push(startVal);
                    par[startVal]=x;
                    startVal++;
                } else {
                    q.push(endVal);
                    par[endVal]=x;
                    endVal--;
                    q.push(endVal);
                    par[endVal]=x;
                    endVal--;
                }
            }
        }

        vector<int> res;
        res.push_back(label);

        while(par[label]!=-1) {
            res.push_back(par[label]);
            label=par[label];
        }

        reverse(res.begin(),res.end());

        return res;
    }
};