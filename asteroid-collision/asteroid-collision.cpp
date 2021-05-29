class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> s;
        
        vector<int> res;
        
        for(int i:asteroids){
            
            if(i>0){
                s.push(i);
            }
            else{
                
                bool flag=1;
                
                while(!s.empty()&&flag){
                    
                    int x=s.top();
                    
                    s.pop();
                    
                    if(abs(i)<x){
                        
                        flag=0;
                        
                        s.push(x);
                    }
                    else if(abs(i)==x){
                        
                        flag=0;
                    }
                }
                
                if(flag)
                    res.push_back(i);
            }
        }
        
        int i=res.size();
        
        while(!s.empty()){
            
            res.insert(res.begin()+i,s.top());
            
            s.pop();
        }
                
        return res;
    }
};