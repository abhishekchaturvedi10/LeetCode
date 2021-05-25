class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n=s.size();
        
        if(s[n-1]=='1')
            return 0;
        
        bool vis[n];
        
        memset(vis,0,sizeof(vis));
        
        queue<int> q;
        
        q.push(0);
        
        vis[0]=1;
                
        while(!q.empty()){
            
            int len=q.size();
            
            while(len--){
            
                int i=q.front();
                
                q.pop();
                                                                        
                if(i+minJump<=n-1&&i+maxJump>=n-1)
                    return 1;
                
                if(i+minJump>=n)
                    continue;
                
                int j=i+minJump;
            
                while(j<=i+maxJump){
                    
                    if(vis[j])
                        j=j+maxJump+1;
                    
                    if(j<n&&!vis[j]&&s[j]=='0'){
                        q.push(j);
                        vis[j]=1;
                    }
                    
                    j++;
                }
            }
        }
        
        return 0;
    }
};