class MyCircularQueue {
public:
    
    int sz;
    vector<int> q;
    int beg, end;
    
    MyCircularQueue(int k) {
        
        sz=k;
        beg=0;
        end=0;
    }
    
    bool enQueue(int value) {
                
        if(end-beg==sz)
            return 0;
        
        q.push_back(value);
        
        end++;
        
        return 1;
    }
    
    bool deQueue() {
        
        if(beg==end)
            return 0;
        
        beg++;
        
        return 1;
    }
    
    int Front() {
        
        if(beg==end)
            return -1;
        
        return q[beg];
    }
    
    int Rear() {
        
        if(beg==end)
            return -1;
        
        return q[end-1];
    }
    
    bool isEmpty() {
        
        if(beg==end)
            return 1;
        
        return 0;
    }
    
    bool isFull() {
        
        if(end-beg==sz)
            return 1;
        
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */