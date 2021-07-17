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
    
    ListNode *rev(ListNode *head) {
        
        ListNode *prev=NULL;
                
        while(head) {
            
            ListNode *nxt=head->next;
            
            head->next=prev;
            
            prev=head;
            
            head=nxt;
        }
        
        return prev;
    }
    
    ListNode *mid(ListNode *head) {
        
        ListNode *s=head, *f=head;
        
        while(f&&f->next) {
            
            s=s->next;
            
            f=f->next;
            
            if(!f->next)
                break;
            
            f=f->next;
        }
        
        return s;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(!head||!head->next)
            return 1;
        
        ListNode* l=head;
        
        ListNode *m=mid(l);
        
        ListNode* r=rev(m);
        
        while(r&&l) {
            if(r->val!=l->val)
                return 0;
            r=r->next;
            l=l->next;
        }
        
        return 1;
    }
};