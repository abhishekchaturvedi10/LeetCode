class MyCircularDeque {
public:
    
    int sz;
    
    vector<int> front, last;
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        sz=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        
        if(front.size()+last.size()<sz){
            
            front.push_back(value);
            
            return 1;
        }
        
        return 0;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        
        if(front.size()+last.size()<sz){
            
            last.push_back(value);
            
            return 1;
        }
        
        return 0;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        
        if(front.size()+last.size()==0)
            return 0;
        
        if(front.size()>0)
            front.pop_back();
        else
            last.erase(last.begin());
        
        return 1;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        
        if(front.size()+last.size()==0)
            return 0;
        
        if(last.size()>0)
            last.pop_back();
        else
            front.erase(front.begin());
        
        return 1;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        
        if(front.size()+last.size()==0)
            return -1;
        
        if(front.size()>0)
            return front[front.size()-1];
        else
            return last[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        
        if(front.size()+last.size()==0)
            return -1;
        
        if(last.size()>0)
            return last[last.size()-1];
        else
            return front[0];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(front.size()+last.size()==0)
            return 1;
        
        return 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(front.size()+last.size()==sz)
            return 1;
        
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */