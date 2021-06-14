class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if(arr.size()==1)
            return arr[0];
        
        if(k>=arr.size())
            return *max_element(arr.begin(),arr.end());
        
        int c=0;
        
        priority_queue<pair<int,int>> pq;
        
        for(int i:arr)
            pq.push({c--,i});
        
        int cnt=0, prev=0;
        
        while(1){
            
            auto x=pq.top();
            pq.pop();
            
            auto y=pq.top();
            pq.pop();
            
            // cout<<x.second<<" "<<y.second<<"\n";
            
            if(x.second>y.second){
                
                if(cnt==0)
                    cnt++, prev=x.second;
                else{
                    if(prev==x.second)
                        cnt++;
                    else
                        cnt=1, prev=x.second;
                }
                
                if(cnt==k)
                    return x.second;
                
                pq.push({c--,y.second});
                
                pq.push({x.first,x.second});
            }
            else {
                if(cnt==0)
                    cnt++, prev=y.second;
                else{
                    if(prev==y.second)
                        cnt++;
                    else
                        cnt=1, prev=y.second;
                }
                
                if(cnt==k)
                    return y.second;
                
                pq.push({c--,x.second});
                
                pq.push({y.first,y.second});
            }
        }
    }
};