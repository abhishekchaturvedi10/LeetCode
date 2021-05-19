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
    ListNode* swapPairs(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode *prev=head;
        ListNode *cur=head->next;
        
        head=cur;
        
        while(true){
            
            ListNode *next=cur->next;
            
            cur->next=prev;
            
            if(!next||!next->next){
                prev->next=next;
                break;
            }
            
            prev->next=next->next;
            
            prev=next;
            cur=prev->next;
            
        }
        
        return head;
    }
};