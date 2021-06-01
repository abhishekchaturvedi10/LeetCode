/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int res;
    
    int peak(int s, int e, MountainArray &mountainArr){
        
        int l=s,r=e;
        
        while(r>l){
            
            int m=l+(r-l)/2;
            
            if(mountainArr.get(m)<mountainArr.get(m+1))
                l=m+1;
            else
                r=m;
        }
        
        return l;
    }
    
    void bsl(int tar, int s, int e, MountainArray &mountainArr){
        
        if(s==e){
            
            if(mountainArr.get(s)==tar)
                res=min(res,s);
        }
        
        int l=s,r=e;
        
        while(r>l){
            
            int m=l+(r-l)/2;
                    
            if(mountainArr.get(m)==tar)
                res=min(res,m);
            
            if(mountainArr.get(m)>tar)
                r=m;
            else
                l=m+1;
        }
        
        if(mountainArr.get(l)==tar)
            res=min(res,l);
    }
    
    void bsr(int tar, int s, int e, MountainArray &mountainArr){
        
        if(s==e){
            
            if(mountainArr.get(s)==tar)
                res=min(res,s);
        }
        
        int l=s,r=e;
        
        while(r>l){
            
            int m=l+(r-l)/2;
            
            // cout<<l<<" "<<r<<" "<<m<<'\n';
            
            if(mountainArr.get(m)==tar)
                res=min(res,m);
            
            if(mountainArr.get(m)>=tar)
                l=m+1;
            else
                r=m;
        }
        
        if(mountainArr.get(l)==tar)
            res=min(res,l);
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peakIndex=peak(0,mountainArr.length()-1,mountainArr);
        
        res=INT_MAX;
        
        if(mountainArr.get(peakIndex)==target)
            res=min(res,peakIndex);
        
        bsl(target,0,peakIndex-1,mountainArr);
        
        bsr(target,peakIndex+1,mountainArr.length()-1,mountainArr);
        
        return res==INT_MAX?-1:res;
    }
};