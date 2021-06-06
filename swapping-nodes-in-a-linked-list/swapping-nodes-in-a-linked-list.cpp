/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* cur=head;
        
        int len=0;
        
        while(cur){
            len++;
            cur=cur->next;
        }
        
        if(len&1&&len-k+1==k)
            return head;
        
        int a,b;
        
        if(k>len-k+1){
            a=len-k+1;
            b=k;
        }
        else{
            a=k;
            b=len-k+1;
        }
          
        cur=head;
        
        int cnt=0, val1, val2;
        
        while(cnt<b){
            
            cnt++;
                        
            if(a==cnt){
                val1=cur->val;
            }
            
            if(b==cnt){
                val2=cur->val;
                cur->val=val1;
            }
            
            cur=cur->next;
        }
        
        cur=head;
        
        cnt=0;
        
        while(cnt<a){
            
            cnt++;
            
            if(a==cnt){
                cur->val=val2;
            }
            
            cur=cur->next;
        }
        
        return head;
    }
};