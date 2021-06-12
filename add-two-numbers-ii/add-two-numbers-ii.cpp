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
    
    ListNode* reverse(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        
        while(cur){
            
            ListNode* nxt=cur->next;
            
            cur->next=prev;
            
            prev=cur;
            
            cur=nxt;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=reverse(l1);
        l2=reverse(l2);
        
        int carry=0;
        
        ListNode* dummy = new ListNode(0);
        ListNode* res=dummy;
        
        while(l1&&l2){
            
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            dummy->next=new ListNode(sum);
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
            
            int sum=l1->val+carry;
            carry=sum/10;
            sum=sum%10;
            dummy->next=new ListNode(sum);
            dummy=dummy->next;
            l1=l1->next;
        }
        
        while(l2){
            
            int sum=l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            dummy->next=new ListNode(sum);
            dummy=dummy->next;
            l2=l2->next;
        }
        
        if(carry>0)
            dummy->next=new ListNode(carry);
        
        res=reverse(res->next);
        
        return res;
    }
};