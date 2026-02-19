class MedianFinder {
    
private:    

    priority_queue<int> chote;
    priority_queue<int, vector<int>, greater<>> bade;

public:    
        
    void addNum(int num) {
        
        if(chote.size()==0||num<chote.top())
            chote.push(num);
        else
            bade.push(num);
        
        if(chote.size()>bade.size()+1) {
            bade.push(chote.top());
            chote.pop();
        } else if(bade.size()>chote.size()+1) {
            chote.push(bade.top());
            bade.pop();
        }
    }
    
    double findMedian() {
        
        if(chote.size()==bade.size()) {
            return (chote.top()+bade.top())/2.0;
        }
        
        if(chote.size()>bade.size())
            return chote.top();
        
        return bade.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */