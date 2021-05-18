class LRUCache {
public:
    
    unordered_map<int,list<pair<int,int>>::iterator> m;
    
    list<pair<int,int>> l;
    
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end())
            return -1;
        
        // Transfer key to beginning of the list
        l.splice(l.begin(), l, m[key]);
            
        return m[key]->second;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            l.splice(l.begin(), l, m[key]);
            m[key]->second=value;
        }
        else{
            if(cap==m.size()){
                int del_key=l.back().first;
                l.pop_back();
                m.erase(del_key);
            }
            l.push_front({key,value});
            m.insert({key,l.begin()});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */