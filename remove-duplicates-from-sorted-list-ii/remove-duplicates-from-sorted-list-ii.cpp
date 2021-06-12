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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head||!head->next)
            return head;
        
        ListNode* cur=head->next;
        
        if(head->next->val==head->val){
            while(cur&&head->val==cur->val){
                cur=cur->next;
            }
            
            head=cur;
        }
        
        
        ListNode* prev=head;
        
        while(cur){
            if(!cur->next)
                break;
            if(cur->next&&cur->val!=cur->next->val){
                prev=cur;
                cur=cur->next;
            }
            else{
                ListNode* temp=cur;
                while(cur&&temp->val==cur->val){
                    cur=cur->next;
                }
                prev->next=cur;
                if(temp->val==head->val)
                    head=cur;
            }
        }
        
        return head;
    }
};