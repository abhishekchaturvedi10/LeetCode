class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i:arr)
            pq.push({abs(i-x),i});
        vector<int> res(k);
        while(k--){        
            res[k]=pq.top().second;
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};