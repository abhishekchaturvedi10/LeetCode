class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int m = arr[(arr.size()-1)/2];

        priority_queue<vector<int>> maxHeap;

        for(int i:arr) {
            maxHeap.push({abs(i-m),i});
        }

        vector<int> res;

        while(res.size()<k) {
            res.push_back(maxHeap.top()[1]);
            maxHeap.pop();
        }

        return res;
    }
};