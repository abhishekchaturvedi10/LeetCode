/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        bool checkcycle=false;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                checkcycle=true;
                break;
            }
        }
        if(!checkcycle)
            return NULL;
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};