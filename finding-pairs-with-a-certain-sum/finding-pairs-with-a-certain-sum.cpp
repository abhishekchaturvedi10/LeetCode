class FindSumPairs {
public:
    
    unordered_map<int,int> m1,m2;
    
    vector<int> a;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i:nums1)
            m1[i]++;
        
        for(int i:nums2)
            m2[i]++;
        
        a=nums2;
    }
    
    void add(int index, int val) {
        m2[a[index]]--;
        a[index]+=val;
        m2[a[index]]++;
    }
    
    int count(int tot) {
        
        int cnt=0;
        
        for(auto i:m1)
            cnt+=i.second*m2[tot-i.first];
                
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */