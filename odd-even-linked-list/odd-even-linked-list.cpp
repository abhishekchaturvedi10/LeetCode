/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)
            return head;
        ListNode *odd=head;
        ListNode *o=odd;
        ListNode *even=head->next;
        ListNode *e=even;
        int count=3;
        head=head->next->next;
        while(head){
            if(count%2){
                odd->next=head;
                odd=odd->next;
            }
            else{
                even->next=head;
                even=even->next;
            }
            head=head->next;
            count++;
        }
        even->next=NULL;
        odd->next=e;
        return o;
    }
};
