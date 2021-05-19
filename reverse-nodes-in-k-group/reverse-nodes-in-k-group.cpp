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
    ListNode* reverseKGroup(ListNode* head, int k) {
                
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
    
        int cnt=0;
        
        while(cur){
            cnt++;
            cur=cur->next;
        }
        
        if(cnt<k){
            return head;
        }
        
        cnt=0;
        
        cur=head;
        
        while(cur && cnt<k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        
        if(next)
            head->next = reverseKGroup(next, k);
        
        return prev;
    }
};