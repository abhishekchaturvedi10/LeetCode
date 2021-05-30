class CustomStack {
public:
    
    deque<int> q;
    int size;
    
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        
        if(q.size()<size)
            q.push_back(x);
    }
    
    int pop() {
        
        if(!q.size())
            return -1;
        else{
            
            int x=q.back();
            q.pop_back();
            
            return x;
        }
    }
    
    void increment(int k, int val) {
        
        deque<int> temp;
        
        while(q.size()&&k--){
            
            temp.push_back(q.front()+val);
            
            q.pop_front();
        }
        
        while(q.size()){
            
            temp.push_back(q.front());
            
            q.pop_front();
        }
        
        q=temp;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */