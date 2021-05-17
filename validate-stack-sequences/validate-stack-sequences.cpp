class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> s;
        
        int j=0;
        
        for(int i:pushed){
            s.push(i);
            while(!s.empty()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        
        return s.empty();
    }
};