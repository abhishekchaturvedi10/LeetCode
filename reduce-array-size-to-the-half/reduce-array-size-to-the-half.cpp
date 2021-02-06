class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for(int i:arr)
            m[i]++;
        priority_queue<pair<int, int>> maxheap;
        for(auto i:m)
            maxheap.push({i.second, i.first});
        int res=0, x=0;
        while(maxheap.size()>0){
            if(x>=arr.size()/2)
                return res;
            pair<int, int> p=maxheap.top();
            x+=p.first;
            maxheap.pop();
            res++;
        }
        return res;
    }
};