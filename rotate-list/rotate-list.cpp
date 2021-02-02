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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!k)
            return head;
        int len=0;
        ListNode *cur=head;
        while(cur)
            len++, cur=cur->next;
        k%=len;
        if(!k)
            return head;
        int cnt=1;
        ListNode *x=head;
        ListNode *y=x;
        while(cnt<len-k){
            x=x->next;
            cnt++;
        }
        ListNode *z=x->next;
        ListNode *ans=z;
        x->next=NULL;
        while(z->next)
            z=z->next;
        z->next=y;
        return ans;
    }
};