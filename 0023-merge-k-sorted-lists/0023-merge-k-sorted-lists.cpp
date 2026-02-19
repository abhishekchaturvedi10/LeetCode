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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<>> pq;
        for(ListNode* list:lists) {
            ListNode* l=list;
            while(l!=nullptr) {
                pq.push(l->val);
                l=l->next;
            }
        }

        ListNode* res=new ListNode(0);
        ListNode* d=res;
        while(!pq.empty()) {
            d->next=new ListNode(pq.top());
            d=d->next;
            pq.pop();
        }
        
        return res->next;
    }
};