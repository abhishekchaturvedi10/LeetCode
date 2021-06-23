class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        
        int cnt=1;
        
        for(int i=1;i<a.size();i++){
            
            if(a[i]==a[i-1]){
                
                cnt++;
                
                if(cnt>2){
                    
                    int ind = upper_bound(a.begin(),a.end(),a[i])-a.begin();
                    
                    if(ind==a.size()){
                        while(a.size()>i)
                            a.pop_back();
                            
                        break;
                    }
                    
                    int x=ind-i;
                    
                    for(int j=ind;j<a.size();j++)
                        a[j-x]=a[j];
                    
                    while(x--)
                        a.pop_back();
                    
                    cnt=1;
                }
            }
            else
                cnt=1;
        }
        
        return a.size();
    }
};