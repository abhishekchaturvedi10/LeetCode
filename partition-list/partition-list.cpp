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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head||!head->next)
            return head;
        
        ListNode* res=new ListNode(0);
        ListNode* res1=res;
                
        ListNode* cur=head;
        ListNode* prev=NULL;
        
        while(cur){
            
            if(cur->val<x){
                
                res1->next=new ListNode(cur->val);
                res1=res1->next;
                
                if(!prev){
                    cur=cur->next;
                    head=cur;
                    continue;
                }
                
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                
                prev=cur;
                cur=cur->next;
            }
        }
        
        res1->next=head;
        
        return res->next;
    }
};