class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        unordered_map<int,int> s, vis1,vis2;
                
        for(int i:forbidden)
            s[i]=1;
        
        if(s[0])
            return -1;
        
        queue<vector<int>> q;
        
        q.push({0,1});
                
        vis1[0]=1;
        
        int steps=0;
        
        while(!q.empty()){
            
            int len=q.size();
            
            while(len--){
                
                auto v=q.front();
                
                q.pop();
                
                if(v[0]==x)
                    return steps;
                                
                if(!s[v[0]+a]&&!vis1[v[0]+a]&&v[0]+a<=6000){
                    vis1[v[0]+a]=1;
                    q.push({v[0]+a,1});
                }
                    
                if(v[0]-b<0||v[1]==2||s[v[0]-b]||vis2[v[0]-b])
                    continue;
                    
                vis2[v[0]-b]=1;
                q.push({v[0]-b,2});
            }
            
            steps++;
        }
        
        return -1;
    }
};