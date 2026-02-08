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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        int prevCarry = 0;
        int curSum = 0;
        while(l1 || l2) {
            curSum = prevCarry;
            if(l1) {
                curSum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                curSum += l2->val;
                l2 = l2->next;
            }
            prevCarry = curSum/10;
            curSum = curSum%10;
            dummy->next = new ListNode(curSum);
            dummy = dummy->next;
        }
        if(prevCarry>0) {
            dummy->next = new ListNode(prevCarry);
        }
        return res->next;
    }
};