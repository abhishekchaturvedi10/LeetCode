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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        
        struct ListNode *cur=l1;
        
        struct ListNode *ath;
        struct ListNode *bth;
        
        int count=1;
        
        while(count<=b+1){
            if(count==a)
                ath=cur;
            count++;
            cur=cur->next;
        }
        
        bth=cur;
        
        ath->next=l2;
        
        while(ath->next){
            ath=ath->next;
        }
        
        ath->next=bth;
                
        return l1;
    }
};