class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        int i=0, j=costs.size()-1;
        long long res=0;

        while(j>=i && pq.size()<2*candidates) {
            if(i==j) {
                pq.push({costs[i],i});
            } else {
                pq.push({costs[i],i});
                pq.push({costs[j],j});
            }
            i++;
            j--;
        }

        int candidatesChosen = 0;

        while(candidatesChosen<k && pq.size()) {
            vector<int> t = pq.top();
            res+=t[0];
            pq.pop();
            if (j>=i) {
                if(t[1]<=i) {
                    pq.push({costs[i],i});
                    i++;
                } else {
                    pq.push({costs[j],j});
                    j--;
                }
            }
            candidatesChosen++;
        }

        return res;
    }
};