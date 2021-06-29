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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* i=head;
        ListNode* res=head;
        ListNode* prev=NULL;
        
        while(i) {
            
            int s=i->val;
            
            ListNode* j=i->next;
            
            while(s!=0&&j) {
                
                s+=j->val;
                
                j=j->next;
            }
            
            if(s==0) {
                if(prev) {
                    prev->next=j;
                    i=j;
                }
                else{
                    res=j;
                    i=j;
                    if(j)
                        j=j->next;
                }
            }
            else {
                
                prev=i;
                
                if(i)
                    i=i->next;
                if(i&&i->next)
                    j=i->next;
            }
        }
        
        return res;
    }
};