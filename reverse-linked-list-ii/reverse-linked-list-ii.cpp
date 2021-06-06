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
    
    ListNode* reverseBetween(struct ListNode* head, int m, int n) {
        
        if(!head||!head->next||m>=n)
            return head;
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        
        while(m-->1){
            
            prev=cur;
            cur=cur->next;
            n--;
        }
        
        ListNode* con=prev;
        ListNode* tail=cur;
        
        while(n--){
            
            ListNode *nxt=cur->next;
            cur->next=prev;
            prev=cur;      
            cur=nxt;
        }
        
        if(con)
            con->next=prev;
        else
            head=prev;
        
        tail->next=cur;
            
        return head;
   }
};