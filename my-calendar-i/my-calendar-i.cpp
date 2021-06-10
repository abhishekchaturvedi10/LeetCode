class MyCalendar {
public:
    
    vector<vector<int>> events;

    bool book(int start, int end) {
        
        for (auto p : events)
            if (max(p[0], start) < min(end, p[1])) 
                return 0;
        
        events.push_back({start, end});
        
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */