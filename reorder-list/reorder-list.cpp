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
    
    void reorderList(ListNode* head) {
                          
        ListNode* h=head;
        
        stack<ListNode*> s;
        
        int len=0;
        
        while(h){
            s.push(h);
            h=h->next;
            len++;
        }
        
        ListNode* x=head;
        
        int y=len-(len+1)/2;
    
        while(y--){
            
            ListNode* z=s.top();
            ListNode* zz=x->next;
            x->next=z;
            z->next=zz;
            x=x->next->next;
            s.pop();
        }
        
        x->next=NULL;
    }
};