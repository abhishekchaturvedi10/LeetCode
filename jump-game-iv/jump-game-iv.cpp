class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        map<int,vector<int>> m;
        
        for(int i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        
        queue<int> q;
        
        q.push(0);
        
        vector<int> vis(arr.size());
        
        map<int,int> vis1;
        
        int moves=0;
                
        while(!q.empty()){
            
            int len=q.size();
            
            while(len--){
                
                int f=q.front();
                                
                q.pop();
                
                vis[f]=1;
                
                if(f==arr.size()-1)
                    return moves;
                
                if(f+1<arr.size()&&!vis[f+1]&&arr[f]!=arr[f+1])
                    q.push(f+1);
                
                if(f-1>=0&&!vis[f-1]&&arr[f]!=arr[f-1])
                    q.push(f-1);
                
                if(vis1[arr[f]])
                    continue;
                
                vis1[arr[f]]=1;
                
                for(int i:m[arr[f]])
                    if(!vis[i]&&i!=f)
                        q.push(i);
            }
            
            moves++;
        }
        
        return -1;
    }
};